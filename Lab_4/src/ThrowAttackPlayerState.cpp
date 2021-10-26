#include "Events.h"

#include "FSM/ThrowAttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/DiedPlayerState.h"
#include <iostream>

PlayerState* ThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		std::cout << "THROW ATTACK -> RUN RIGHT" << std::endl;
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_STOP_EVENT)
	{
		std::cout << "THROW ATTACK -> IDLE" << std::endl;
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		std::cout << "THROW ATTACK -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
	return nullptr;
}
void ThrowAttackPlayerState::update(Player& player) {}
void ThrowAttackPlayerState::enter(Player& player)
{
	std::cout << "ENTERING THORW ATTACK" << std::endl;
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{6075, 0, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6452, 0, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6829, 0, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6075, 451, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6452, 451, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6829, 451, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6075, 902, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6452, 902, 377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6829, 902,377, 451});
	player.getAnimatedSprite().addFrame(SDL_Rect{6075, 1353, 377, 451});

	player.getAnimatedSprite().setTime(0.03f);
}
void ThrowAttackPlayerState::exit(Player& player)
{
	std::cout << "LEAVING THROW ATTACk" << std::endl;
}