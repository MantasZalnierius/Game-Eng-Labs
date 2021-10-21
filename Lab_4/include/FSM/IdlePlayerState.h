#ifndef IDLE_PLAYER_STATE_H
#define IDLE_PLAYER_STATE_H

#include "Player.h"
#include "FSM/PlayerState.h"

class IdlePlayerState : public PlayerState{
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual ~IdlePlayerState() {};
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
};
#endif