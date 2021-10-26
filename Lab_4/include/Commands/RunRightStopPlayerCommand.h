#pragma once

#include <vector>
#include "Commands/Command.h"

class RunRightStopPlayerCommand : public Command
{
public:
    virtual ~RunRightStopPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING RUN RIGHT STOP COMMAND" << std::endl;
         t_event.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
    }
};