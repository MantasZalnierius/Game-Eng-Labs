#pragma once

#include <vector>
#include "Commands/Command.h"

class JumpPlayerCommand : public Command
{
public:
    virtual ~JumpPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING JUMP COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
    }
};