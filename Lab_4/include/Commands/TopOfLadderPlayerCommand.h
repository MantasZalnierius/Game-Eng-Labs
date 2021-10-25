#pragma once

#include <vector>
#include "Commands/Command.h"

class TopOfLadderPlayerCommand : public Command
{
public:
    virtual ~TopOfLadderPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
       t_event.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
    }
};