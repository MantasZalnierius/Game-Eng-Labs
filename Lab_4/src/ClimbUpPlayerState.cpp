#include "Events.h"

#include "FSM/ClimbUpPlayerState.h"

#include "FSM/ClimbPausePlayerState.h"
#include "FSM/ClimbDownPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"


PlayerState* ClimbUpPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_UP_STOP_EVENT)
	{
		return new ClimbPausePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		return new DecendLadderPlayerState();
	}
	
	return nullptr;
}
void ClimbUpPlayerState::update(Player& player) {}
void ClimbUpPlayerState::enter(Player& player) 
{
	// Climb Up Animated Sprite
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 1392, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{2172, 928, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1890, 928, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 928, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{2172, 464, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1890, 464, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 464, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{2172, 0, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1890, 0, 282, 464});
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 0, 282, 464});
	
	player.getAnimatedSprite().setTime(0.05f);
}
void ClimbUpPlayerState::exit(Player& player)
{

}