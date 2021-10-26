#include "Events.h"

#include "FSM/JumpThrowAttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/GlidePlayerState.h"
#include "FSM/DiedPlayerState.h"
#include <iostream>

PlayerState* JumpThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		std::cout << "JUMP THROW ATTACK -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_STOP_EVENT)
	{
		std::cout << "JUMP THROW ATTACK -> GLIDE" << std::endl;
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpThrowAttackPlayerState::update(Player& player) {}
void JumpThrowAttackPlayerState::enter(Player& player)
{
	std::cout << "ENTERING JUMP THROW ATTACK" << std::endl;
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{4596, 0, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{4956, 0, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{5316, 0, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{4596, 431, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{4956, 431, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{5316, 431, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{4596, 862, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{4956, 862, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{5316, 862, 360, 431});
	player.getAnimatedSprite().addFrame(SDL_Rect{4596, 1293, 360, 431});

	player.getAnimatedSprite().setTime(0.05f);
}
void JumpThrowAttackPlayerState::exit(Player& player)
{
	std::cout << "LEAVING JUMP THROW ATTACK" << std::endl;
}