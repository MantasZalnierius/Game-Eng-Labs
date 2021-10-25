#pragma once

#include <vector>
#include "Commands/Command.h"

class BottomOfLadderPlayerCommand : public Command
{
public:
    virtual ~BottomOfLadderPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
       t_event.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
    }
};