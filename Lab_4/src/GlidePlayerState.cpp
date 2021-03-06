#include "Events.h"

#include "FSM/GlidePlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include <iostream>

PlayerState* GlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::HIT_GROUND_EVENT)
	{
		std::cout << "GLIDE -> IDLE" << std::endl;
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT)
	{
		std::cout << "GLIDE -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		isMovingInXAxis = true;
	}
		else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_STOP_EVENT)
	{
		isMovingInXAxis = false;
	}
	return nullptr;
}
void GlidePlayerState::update(Player& player) {
	if(isMovingInXAxis) { player.moveRight(2); }
	player.fallingDown(2);
	if (m_clock.getTimerAsSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void GlidePlayerState::enter(Player& player)
{
	std::cout << "ENTERING GLIDE" << std::endl;
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{0, 1992, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{443, 1992, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{886, 1992, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 2446, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{443, 2446, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{886, 2446, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 2900, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{443, 2900, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{886, 2900, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 3354, 443, 454});

	player.getAnimatedSprite().setTime(0.03f);
}
void GlidePlayerState::exit(Player& player)
{
	std::cout << "LEAVING GLIDE" << std::endl;
}