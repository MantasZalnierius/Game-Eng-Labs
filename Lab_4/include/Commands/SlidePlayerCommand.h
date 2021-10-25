#pragma once

#include <vector>
#include "Commands/Command.h"

class SlidePlayerCommand : public Command
{
public:
    virtual ~SlidePlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        t_event.setCurrent(gpp::Events::Event::SLIDE_EVENT);
    }
};