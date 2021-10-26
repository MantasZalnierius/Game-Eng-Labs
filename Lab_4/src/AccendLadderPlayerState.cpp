#include "Events.h"

#include "FSM/AccendLadderPlayerState.h"

#include "FSM/ClimbUpPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"
#include <iostream>

PlayerState* AccendLadderPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_UP_START_EVENT)
	{
		std::cout << "IDLE -> CLIMB UP" << std::endl;
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		std::cout << "IDLE -> RUN RIGHT" << std::endl;
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		std::cout << "IDLE -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
	return nullptr;
}
void AccendLadderPlayerState::update(Player& player) {}
void AccendLadderPlayerState::enter(Player& player)
{
	std::cout << "ENTERING ACCEND LADDER" << std::endl;
	player.getAnimatedSprite().clearFrames();
	player.getAnimatedSprite().addFrame(SDL_Rect{1608,464,282,464});
	player.getAnimatedSprite().setTime(0.05f);
}
void AccendLadderPlayerState::exit(Player& player)
{
	std::cout << "ACCENDING LADDER STATE" << std::endl;
}