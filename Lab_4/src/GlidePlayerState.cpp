#include "Events.h"

#include "FSM/GlidePlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"

PlayerState* GlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::HIT_GROUND_EVENT)
	{
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT)
	{
		return new DiedPlayerState();
	}
	return nullptr;
}
void GlidePlayerState::update(Player& player) {
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
}