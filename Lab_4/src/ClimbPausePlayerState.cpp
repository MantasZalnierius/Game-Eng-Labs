#include "Events.h"

#include "FSM/ClimbPausePlayerState.h"

#include "FSM/ClimbDownPlayerState.h"
#include "FSM/ClimbUpPlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"
#include <iostream>


PlayerState* ClimbPausePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		std::cout << "CLIMB PAUSE -> CLIMB DOWN" << std::endl;
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::MOVE_UP_START_EVENT)
	{
		std::cout << "CLIMB PAUSE -> CLIMB UP" << std::endl;
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		std::cout << "CLIMB PAUSE -> BOTTOM OF LADDER" << std::endl;
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		std::cout << "CLIMB PAUSE -> TOP OF LADDER" << std::endl;
		return new DecendLadderPlayerState();
	}
	return nullptr;
}
void ClimbPausePlayerState::update(Player& player) {}
void ClimbPausePlayerState::enter(Player& player)
{
	std::cout << "ENTERING CLIMB PAUSE" << std::endl;
	player.getAnimatedSprite().clearFrames();
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 464, 282, 464});
	player.getAnimatedSprite().setTime(0.05f);
}
void ClimbPausePlayerState::exit(Player& player) 
{
	std::cout << "LEAVING CLIMB PAUSE" << std::endl;
}