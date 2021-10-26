#pragma once

#include <vector>
#include "Commands/Command.h"

class SlidePlayerCommand : public Command
{
public:
    virtual ~SlidePlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING SLIDE COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::SLIDE_EVENT);
    }
};