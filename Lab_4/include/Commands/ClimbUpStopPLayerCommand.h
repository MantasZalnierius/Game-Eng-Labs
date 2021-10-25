#pragma once

#include <vector>
#include "Commands/Command.h"

class ClimbUpStopPlayerCommand : public Command
{
public:
    virtual ~ClimbUpStopPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        t_event.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
    }
};