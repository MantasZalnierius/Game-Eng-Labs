#include <stdio.h>
#include "Player.h"
#include "Events.h"
#include "FSM/IdlePlayerState.h"
#include <iostream>


Player::Player(const AnimatedSprite& sprite) : m_animated_sprite(sprite)
{
	// Set the Player to Default to IdlePlayer State 
	// and Enter that State
	m_state = new IdlePlayerState();
	m_state->enter(*this);
}

void Player::handleInput(gpp::Events input) {
	PlayerState * state = m_state->handleInput(input);

	if (state != NULL) {
		m_state->exit(*this);
		delete m_state;
		m_state = state;
		m_state->enter(*this);
	}
}

void Player::update() {
	m_animated_sprite.update();
	m_state->update(*this);
}

AnimatedSprite& Player::getAnimatedSprite() {
	return m_animated_sprite;
}

AnimatedSprite& Player::getAnimatedSpriteFrame() {
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::setAnimatedSprite(AnimatedSprite& animated_sprite) {
	m_animated_sprite = animated_sprite;
}

PlayerState* Player::getPlayerState() { return this->m_state; }

void Player::render(SDL_Renderer* t_renderer)
{
	getAnimatedSpriteFrame().render(m_x, m_y, t_renderer);
}

void Player::setPlayerState(PlayerState* state) { this->m_state = state; }

void Player::moveRight(int t_speed)
{
	m_x += 0.005f * t_speed;
}

void Player::jumpUp(int t_speed)
{
	m_y -= 0.005f * t_speed;
}

void Player::fallingDown(int t_speed)
{
	m_y += 0.005f * t_speed;
}