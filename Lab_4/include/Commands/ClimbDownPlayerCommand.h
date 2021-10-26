#pragma once

#include <vector>
#include "Commands/Command.h"
#include <iostream>

class ClimbDownPlayerCommand : public Command
{
public:
    virtual ~ClimbDownPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING CLIMB DOWN COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
    }
};