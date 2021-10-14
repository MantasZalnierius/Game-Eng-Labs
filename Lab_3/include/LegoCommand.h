#pragma once

#include "../include/Command.h"
#include "../include/BrickFactory.h"
#include "../include/Brick.h"
#include <iostream>

class LegoCommand : public Command
{
public: 
    LegoCommand() = default;

    virtual void execute(std::vector<Brick*>& t_bricks)
    {
        t_bricks.push_back(m_legoFactory.CreateBrick());
        m_counter = 0;
    }

    virtual void undo()
    {
    }

private:
    LegoFactory m_legoFactory;
};