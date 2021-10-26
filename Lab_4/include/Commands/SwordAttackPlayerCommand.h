#pragma once

#include <vector>
#include "Commands/Command.h"

class SwordAttackPlayerCommand : public Command
{
public:
    virtual ~SwordAttackPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING SWORD ATTACK COMMAND" << std::endl;
        t_event.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
    }
};