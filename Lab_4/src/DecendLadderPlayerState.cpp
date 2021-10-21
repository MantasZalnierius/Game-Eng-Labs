#include "Events.h"

#include "FSM/DecendLadderPlayerState.h"

#include "FSM/ClimbDownPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* DecendLadderPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		return new ClimbDownPlayerState();
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
void DecendLadderPlayerState::update(Player& player) {}
void DecendLadderPlayerState::enter(Player& player)
{
	player.getAnimatedSprite().clearFrames();
	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 464, 282, 464});
	player.getAnimatedSprite().setTime(0.05f);
}
void DecendLadderPlayerState::exit(Player& player)
{
}