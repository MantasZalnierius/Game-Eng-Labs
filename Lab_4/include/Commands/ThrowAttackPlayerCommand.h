#pragma once

#include <vector>
#include "Commands/Command.h"

class ThrowAttackPlayerCommand : public Command
{
public:
    virtual ~ThrowAttackPlayerCommand() {}
    void execute(gpp::Events& t_event)
    {
        std::cout << "EXECUTING THROW ATTACK COMMAND" << std::endl;
       t_event.setCurrent(gpp::Events::Event::THROW_START_EVENT);
    }
};