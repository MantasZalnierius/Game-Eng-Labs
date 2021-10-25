#pragma once

#include <vector>
#include "Commands/Command.h"

class DiedPlayerCommand : public Command
{
public:
    virtual ~DiedPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        t_event.setCurrent(gpp::Events::Event::DIED_EVENT);
    }
};