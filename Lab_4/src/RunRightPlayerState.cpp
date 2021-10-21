#include "Events.h"

#include "FSM/RunRightPlayerState.h"

#include "FSM/AttackPlayerState.h"
#include "FSM/ThrowAttackPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include "FSM/AccendLadderPlayerState.h"
#include "FSM/DecendLadderPlayerState.h"
#include "FSM/JumpPlayerState.h"
#include "FSM/DiedPlayerState.h"
#include "FSM/SlidePlayerState.h"
#include <iostream>

PlayerState* RunRightPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		return new AttackPlayerState();
	}
	if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_WALL_EVENT || input.getCurrent() == gpp::Events::Event::RUN_RIGHT_STOP_EVENT)
	{
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::JUMP_UP_EVENT) {
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::SLIDE_EVENT) {
		return new SlidePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		return new DiedPlayerState();
	}
	return nullptr;
}
void RunRightPlayerState::update(Player& player) {}
void RunRightPlayerState::enter(Player& player)
{
	player.getAnimatedSprite().clearFrames();
	player.getAnimatedSprite().addFrame(SDL_Rect{4986, 3556, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{5349, 3556, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{5712, 3556, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{4986, 4014, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{5349, 4014, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{5712, 4014, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{4986, 4472, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{5349, 4472, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{5712, 4472, 363, 458});
	player.getAnimatedSprite().addFrame(SDL_Rect{4986, 4930, 363, 458});

	player.getAnimatedSpriteFrame().setTime(0.05f);
}
void RunRightPlayerState::exit(Player& player) 
{
}