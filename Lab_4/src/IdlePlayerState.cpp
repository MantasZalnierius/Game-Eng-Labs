#include "Events.h"

#include "FSM/IdlePlayerState.h"

#include "FSM/AttackPlayerState.h"
#include "FSM/ThrowAttackPlayerState.h"
#include "FSM/RunRightPlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"
#include "FSM/JumpPlayerState.h"
#include "FSM/DiedPlayerState.h"
#include <iostream>

PlayerState* IdlePlayerState::handleInput(gpp::Events& input) {
    if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		std::cout << "IDLE -> SWORD ATTACK" << std::endl;
		return new AttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		std::cout << "IDLE -> THROW ATTACK" << std::endl;
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT) {
		std::cout << "IDLE -> RUN RIGHT" << std::endl;
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT) {
		std::cout << "IDLE -> ACCEMD LADDER" << std::endl;
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT) {
		std::cout << "IDLE -> DECEND LADDER" << std::endl;
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::JUMP_UP_EVENT) {
		std::cout << "IDLE -> JUMP" << std::endl;
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		std::cout << "IDLE -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
    return nullptr;
}

void IdlePlayerState::update(Player& player) {}

void IdlePlayerState::enter(Player& player) 
{
	std::cout << "ENTERING IDLE" << std::endl;
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
	std::cout << "LEAVING IDLE" << std::endl;
}