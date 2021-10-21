#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

#include "Events.h"
#include <SDL.h>

class Player;

class PlayerState {
public:
	virtual ~PlayerState() {};
	virtual PlayerState* handleInput(gpp::Events&) = 0;
	virtual void update(Player&) = 0;
	virtual void enter(Player&) = 0;
	virtual void exit(Player&) = 0;
};
#endif