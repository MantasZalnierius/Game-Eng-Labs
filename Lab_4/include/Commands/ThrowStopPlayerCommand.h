#pragma once

#include <vector>
#include "Commands/Command.h"

class ThrowStopPlayerCommand : public Command
{
public:
    virtual ~ThrowStopPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
       t_event.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
    }
};