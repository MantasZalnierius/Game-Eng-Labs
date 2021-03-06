#include "Events.h"

#include "FSM/JumpPlayerState.h"

#include "FSM/DiedPlayerState.h"
#include "FSM/JumpAttackPlayerState.h"
#include "FSM/JumpThrowAttackPlayerState.h"
#include "FSM/GlidePlayerState.h"
#include <iostream>

PlayerState* JumpPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		std::cout << "JUMP -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		std::cout << "JUMP -> JUMP SWORD ATTACK" << std::endl;
		return new JumpAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		std::cout << "JUMP -> JUMP THROW ATTACK" << std::endl;
		return new JumpThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		isMovingInXAxis = true;
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_STOP_EVENT)
	{
		isMovingInXAxis = false;
	}
	return nullptr;
}
void JumpPlayerState::update(Player& player) {
	if(isMovingInXAxis) { player.moveRight(2); }
	player.jumpUp(2);
	if (m_clock.getTimerAsSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new GlidePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void JumpPlayerState::enter(Player& player)
{
	std::cout << "ENTERING JUMP" << std::endl;
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 1756, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4262, 1756, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4624, 1756, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 2239, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4262, 2239, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4624, 2239, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 2722, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4262, 2722, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4624, 2722, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 3205, 362, 483});

	player.getAnimatedSpriteFrame().setTime(0.03f);
}
void JumpPlayerState::exit(Player& player)
{
	std::cout << "LEAVING JUMP" << std::endl;
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}