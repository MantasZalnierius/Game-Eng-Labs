#ifndef SLIDE_PLAYER_STATE_H
#define SLIDE_PLAYER_STATE_H

#include "Player.h"
#include "FSM/PlayerState.h"
#include "Timer.h"

class SlidePlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
private:
	Timer m_clock;
    float m_timer;
};

#endif