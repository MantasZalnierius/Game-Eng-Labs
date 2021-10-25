#pragma once

#include <vector>
#include "Commands/Command.h"

class ClimbUpPlayerCommand : public Command
{
public:
    virtual ~ClimbUpPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        t_event.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
    }
};