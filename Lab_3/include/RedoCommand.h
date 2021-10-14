#pragma once

#include "../include/MacroCommand.h"
#include "../include/BrickFactory.h"
#include "../include/Brick.h"
#include <iostream>

class RedoCommand : public Command
{
public: 
    RedoCommand() = default;

    virtual void execute(std::vector<Brick*>& t_bricks)
    {

    }

    virtual void undo() 
    {

    }

    void redo(MacroCommand* t_macro)
    {
        t_macro->redu();
    }
};