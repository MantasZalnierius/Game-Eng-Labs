#pragma once

#include "include/Brick.h"
#include <vector>

class Command
{
public:
    virtual ~Command() {}

    virtual void execute(std::vector<Brick*>& t_mats) =0;
    virtual void undo() = 0;

    virtual void add(){}

    virtual void remove(){}

    virtual int getCount(){return m_counter;}

    virtual void addOneCommand() {m_counter = m_counter + 1;}
    virtual void removeOneCommand() {m_counter = m_counter - 1;}
protected:
    int m_counter;
    Command() 
    {
        m_counter = 0;
    }
};