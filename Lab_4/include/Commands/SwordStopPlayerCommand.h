#pragma once

#include <vector>
#include "Commands/Command.h"

class SwordStopPlayerCommand : public Command
{
public:
    virtual ~SwordStopPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING SWORD ATTACK STOP COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
    }
};