#pragma once
#include "command.h"
#include <vector>
#include <stack>

class MacroCommand : public Command
{
public:
    MacroCommand() = default;
    virtual ~MacroCommand() {};
    virtual void addCommand(Command* t_command)
    {
        m_CommandVector.push_back(t_command);
        t_command->addOneCommand();
    }

    virtual void execute(std::vector<Brick*>& t_bricks)
    {
        for(int i = 0; i < m_CommandVector.size(); i++)
        {
            m_CommandVector.at(i)->execute(t_bricks);
        }

        m_CommandVector.clear();
        while(!m_removeCommandStack.empty()) {m_removeCommandStack.pop();}
    }

    virtual void undo()
    {
        if (m_CommandVector.size() > 0 )
        {
            m_removeCommandStack.push(m_CommandVector.at(m_CommandVector.size() - 1));
            m_removeCommandStack.top()->removeOneCommand();
            m_CommandVector.pop_back();
        }
    }

    void redu()
    {
        if (m_removeCommandStack.size() > 0 )
        {
            m_CommandVector.push_back(m_removeCommandStack.top());
            m_removeCommandStack.top()->addOneCommand();
            m_removeCommandStack.pop();
        }
    }

private:
    std::vector<Command*> m_CommandVector;
    std::stack<Command*> m_removeCommandStack;
};