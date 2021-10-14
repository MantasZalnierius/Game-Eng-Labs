#pragma once

#include "../include/Command.h"
#include "../include/BrickFactory.h"
#include "../include/Brick.h"
#include <iostream>

class ConcreteCommand : public Command
{
public: 
    ConcreteCommand() = default;

    virtual void execute(std::vector<Brick*>& t_bricks)
    {
        t_bricks.push_back(m_concreteFactory.CreateBrick());
        m_counter = 0;
    }

    virtual void undo()
    {
    }

private:
    ConcreteFactory m_concreteFactory;
};