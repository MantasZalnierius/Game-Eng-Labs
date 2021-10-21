#include "Events.h"

#include "FSM/JumpThrowAttackPlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/GlidePlayerState.h"
#include "FSM/DiedPlayerState.h"

PlayerState* JumpThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_STOP_EVENT)
	{
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpThrowAttackPlayerState::update(Player& player) {}
void JumpThrowAttackPlayerState::enter(Player& player)
{
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
}