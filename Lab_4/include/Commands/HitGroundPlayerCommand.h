#pragma once

#include <vector>
#include "Commands/Command.h"

class HitGroundPlayerCommand : public Command
{
public:
    virtual ~HitGroundPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        t_event.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
    }
};