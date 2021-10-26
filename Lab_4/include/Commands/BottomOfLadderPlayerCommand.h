#pragma once

#include <vector>
#include "Commands/Command.h"

class BottomOfLadderPlayerCommand : public Command
{
public:
    virtual ~BottomOfLadderPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING BOTTOM OF LADDER COMMAND" << std::endl;
       t_event.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
    }
};