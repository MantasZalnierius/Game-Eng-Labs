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
    };

    virtual void removeCommand()
    {
    };
    virtual void execute(std::vector<Brick*>& t_mats)override
    {
    }

    virtual void undo()override
    {
    };

private:
    std::vector<Command*> m_commandList;
    std::stack<Command*> m_removedCommands;
};