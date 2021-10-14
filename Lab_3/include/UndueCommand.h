#pragma once

#include "../include/MacroCommand.h"
#include "../include/BrickFactory.h"
#include "../include/Brick.h"
#include <iostream>

class UndueCommand : public Command
{
public: 
    UndueCommand() = default;

    virtual void execute(std::vector<Brick*>& t_bricks)
    {

    }

    virtual void undo() 
    {

    }
};