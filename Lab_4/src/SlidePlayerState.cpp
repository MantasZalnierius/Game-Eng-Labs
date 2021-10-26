#include "Events.h"

#include "FSM/SlidePlayerState.h"

#include "FSM/RunRightPlayerState.h"
#include "FSM/DiedPlayerState.h"
#include "FSM/IdlePlayerState.h"
#include <iostream>

PlayerState* SlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		std::cout << "SLIDE -> RUN RIGHT" << std::endl;
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		std::cout << "SLIDE -> DEAD" << std::endl;
		return new DiedPlayerState();
	}
	return nullptr;
}
void SlidePlayerState::update(Player& player) {
	// Switch from SlidePlayerState to IdlePlayerState
	// There is a fixed time at which the slide switched
	// back to IdlePlayerState....as the gameplay programmer
	// you may wish to stop the slide and have an appropriate
	// state and animation at the end of the slide
	// this was added so sliding does not go one indefinitely
	if (m_clock.getTimerAsSeconds() > 2.0f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp; // Delete previous
	}
}
void SlidePlayerState::enter(Player& player)
{
	std::cout << "ENTERING SLIDE" << std::endl;
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{0, 5388, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{373, 5388, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{746, 5388, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 5739, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{373, 5739, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{746, 5739, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 6090, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{373, 6090, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{746, 6090, 373, 351});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 6441, 373, 351});

	player.getAnimatedSpriteFrame().setTime(0.03f);
}
void SlidePlayerState::exit(Player& player)
{
	std::cout << "LEAVING SLIDE" << std::endl;
}