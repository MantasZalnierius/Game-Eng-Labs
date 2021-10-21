#include "Events.h"

#include "FSM/ClimbPausePlayerState.h"

#include "FSM/ClimbDownPlayerState.h"
#include "FSM/ClimbUpPlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"


PlayerState* ClimbPausePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::MOVE_UP_START_EVENT)
	{
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		return new DecendLadderPlayerState();
	}
	return nullptr;
}
void ClimbPausePlayerState::update(Player& player) {}
void ClimbPausePlayerState::enter(Player& player)
{
	player.getAnimatedSprite().clearFrames();
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 464, 282, 464});
	player.getAnimatedSprite().setTime(0.05f);
}
void ClimbPausePlayerState::exit(Player& player) 
{
}