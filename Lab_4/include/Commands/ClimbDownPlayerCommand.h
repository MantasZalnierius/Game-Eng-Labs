#pragma once

#include <vector>
#include "Commands/Command.h"

class ClimbDownPlayerCommand : public Command
{
public:
    virtual ~ClimbDownPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        t_event.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
    }
};