#pragma once

#include <vector>
#include "Commands/Command.h"

class DiedPlayerCommand : public Command
{
public:
    virtual ~DiedPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING DEAD COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::DIED_EVENT);
    }
};