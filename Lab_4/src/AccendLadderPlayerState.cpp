#include "Events.h"

#include "FSM/AccendLadderPlayerState.h"

#include "FSM/ClimbUpPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* AccendLadderPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_UP_START_EVENT)
	{
		return new ClimbUpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		return new DiedPlayerState();
	}
	return nullptr;
}
void AccendLadderPlayerState::update(Player& player) {}
void AccendLadderPlayerState::enter(Player& player)
{
	player.getAnimatedSprite().clearFrames();
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 0, 232, 439});
	player.getAnimatedSprite().setTime(0.05f);
}
void AccendLadderPlayerState::exit(Player& player)
{
}