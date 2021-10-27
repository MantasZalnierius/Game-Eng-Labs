#ifndef JUMP_PLAYER_STATE_H
#define JUMP_PLAYER_STATE_H

#include "Player.h"
#include "FSM/PlayerState.h"
#include "Timer.h"

class JumpPlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
private:
	Timer m_clock;
    float m_timer;
	bool isMovingInXAxis{false};
};

#endif