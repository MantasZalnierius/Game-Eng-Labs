#pragma once

#include "../include/MacroCommand.h"
#include "../include/BrickFactory.h"
#include "../include/Brick.h"
#include <iostream>

class BuildCommand : public Command
{
public: 
    BuildCommand() = default;

    virtual void execute(std::vector<Brick*>& t_bricks)
    {

    }

    virtual void undo() 
    {

    }
    
    void build(MacroCommand* t_macro, std::vector<Brick*>& t_bricks)
    {
        t_macro->execute(t_bricks);
    }
};