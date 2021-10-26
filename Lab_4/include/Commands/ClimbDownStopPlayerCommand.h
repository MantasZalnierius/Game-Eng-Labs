#pragma once

#include <vector>
#include "Commands/Command.h"

class ClimbDownStopPlayerCommand : public Command
{
public:
    virtual ~ClimbDownStopPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING CLIMB DOWN PAUSE COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
    }
};