#pragma once

#include <vector>
#include "Commands/Command.h"

class ReviviedPlayerCommand : public Command
{
public:
    virtual ~ReviviedPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        t_event.setCurrent(gpp::Events::Event::REVIVED_EVENT);
    }
};