#include "Events.h"

#include "FSM/AttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/DiedPlayerState.h"
#include <iostream>

PlayerState* AttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		std::cout << "SWORD ATTACK -> RUN RIGHT" << std::endl;
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		std::cout << "SWORD ATTACK -> IDLE" << std::endl;
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		std::cout << "SWORD ATTACK -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
	return nullptr;
}
void AttackPlayerState::update(Player& player) {}
void AttackPlayerState::enter(Player& player)
{
	std::cout << "ENTERING SOWRD ATTACK" << std::endl;
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{0, 0, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{536, 0, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{1072, 0, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 495, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{536, 495, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{1072, 495, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 990, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{536, 990, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{1072, 990, 536, 495});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 1485, 536, 495});

	player.getAnimatedSprite().setTime(0.03f);
}
void AttackPlayerState::exit(Player& player)
{
	std::cout << "LEAVING SWORD ATTACK " << std::endl;
}