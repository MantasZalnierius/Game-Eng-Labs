#ifndef PLAYER_H
#define PLAYER_H

#include "FSM/PlayerState.h"
#include "AnimatedSprite.h"

class Player
{
private:
	PlayerState* m_state;
	AnimatedSprite m_animated_sprite;

public:
    Player() = default;
	Player(const AnimatedSprite&);
	virtual void handleInput(gpp::Events);
	virtual void update();
	AnimatedSprite& getAnimatedSprite();
	AnimatedSprite& getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite&);
	PlayerState* getPlayerState();
	void setPlayerState(PlayerState*);
	void render(SDL_Renderer* t_renderer);
	void moveRight(int t_speed);
	void jumpUp(int t_speed);
	void fallingDown(int t_speed);
	float m_x{0};
    float m_y{300};
};
#endif

