#include "Events.h"

#include "FSM/ClimbDownPlayerState.h"

#include "FSM/ClimbPausePlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include <iostream>

PlayerState* ClimbDownPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_STOP_EVENT)
	{
		std::cout << "CLIMB DOWN -> CLIMB STOP" << std::endl;
		return new ClimbPausePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		std::cout << "CLIMB DOWN -> BOTTOM OF LADDER" << std::endl;
		return new AccendLadderPlayerState();
	}
	return nullptr;
}
void ClimbDownPlayerState::update(Player& player) {}
void ClimbDownPlayerState::enter(Player& player)
{
	std::cout << "ENTERING CLIMB DOWN" << std::endl;
	// Climb Down Animated Sprite
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 0, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1890, 0, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{2172, 0, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 464, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1890, 464, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{2172, 464, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 928, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1890, 928, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{2172, 928, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 1392, 282, 464});

	player.getAnimatedSprite().setTime(0.05f);
}
void ClimbDownPlayerState::exit(Player& player) 
{
	std::cout << "LEAVING CLIMB DOWN" << std::endl;
}