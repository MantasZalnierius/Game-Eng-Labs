#include "Events.h"

#include "FSM/IdlePlayerState.h"

#include "FSM/AttackPlayerState.h"
#include "FSM/ThrowAttackPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"
#include "FSM/JumpPlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* IdlePlayerState::handleInput(gpp::Events& input) {
    if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		return new AttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT) {
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT) {
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT) {
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::JUMP_UP_EVENT) {
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		return new DiedPlayerState();
	}
    return nullptr;
}

void IdlePlayerState::update(Player& player) {}

void IdlePlayerState::enter(Player& player) 
{
    player.getAnimatedSprite().clearFrames();
    player.getAnimatedSprite().addFrame(SDL_Rect{3900, 0, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{4132, 0, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{4364, 0, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 439, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{4132, 439, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{4364, 439, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 878, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{4132, 878, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{4364, 878, 232, 439});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 1317, 232, 439});
	player.getAnimatedSprite().setTime(0.05f);
}

void IdlePlayerState::exit(Player& player)
{
}