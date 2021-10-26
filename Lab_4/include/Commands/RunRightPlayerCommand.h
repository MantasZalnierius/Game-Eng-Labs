#pragma once

#include <vector>
#include "Commands/Command.h"

class RunRightPlayerCommand : public Command
{
public:
    virtual ~RunRightPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING RUN RIGHT COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
    }
};