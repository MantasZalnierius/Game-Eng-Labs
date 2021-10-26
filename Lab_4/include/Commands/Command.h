#pragma once

#include <vector>
#include "Events.h"
#include <iostream>

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(gpp::Events& t_event) =0;
protected:
    Command() = default;
};