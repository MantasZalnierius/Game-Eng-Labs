#pragma once

#include "../include/Command.h"
#include "../include/BrickFactory.h"
#include "../include/Brick.h"
#include <iostream>

class ClayCommand : public Command
{
public: 
    ClayCommand() = default;

    virtual void execute(std::vector<Brick*>& t_bricks)
    {
        t_bricks.push_back(m_clayFactory.CreateBrick());
        m_counter = 0;
    }

    virtual void undo()
    {
    }

private:
    ClayFactory m_clayFactory;
};