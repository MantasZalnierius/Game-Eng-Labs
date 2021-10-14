#pragma once

#include "../include/Command.h"
#include "../include/BrickFactory.h"
#include "../include/Brick.h"
#include <iostream>

class PlasticCommand : public Command
{
public: 
    PlasticCommand() = default;

    virtual void execute(std::vector<Brick*>& t_bricks)
    {
        t_bricks.push_back(m_plasticFactory.CreateBrick());
        m_counter = 0;
    }

    virtual void undo()
    {
    }
    virtual int getCount(){return m_counter;}

private:
    PlasticFactory m_plasticFactory;
};