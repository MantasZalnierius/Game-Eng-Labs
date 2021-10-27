#pragma once
#include <iostream>
#include "CommandIncludes.h"

class Factory
{
public:
    virtual Command* createCommand() = 0;
};

class BottomOfLadderCommandFactory : public Factory
{
public:
    BottomOfLadderCommandFactory() = default;
    virtual ~BottomOfLadderCommandFactory() {};
    Command* createCommand() { return new BottomOfLadderPlayerCommand();}
};

class ClimbDownCommandFactory : public Factory
{
public:
    ClimbDownCommandFactory() = default;
    virtual ~ClimbDownCommandFactory() {};
    Command* createCommand() { return new ClimbDownPlayerCommand();}
};

class ClimbDownStopCommandFactory : public Factory
{
public:
    ClimbDownStopCommandFactory() = default;
    virtual ~ClimbDownStopCommandFactory() {};
    Command* createCommand() { return new ClimbDownStopPlayerCommand();}
};

class ClimbUpCommandFactory : public Factory
{
public:
    ClimbUpCommandFactory() = default;
    virtual ~ClimbUpCommandFactory() {};
    Command* createCommand() { return new ClimbUpPlayerCommand();}
};

class ClimbUpStopCommandFactory : public Factory
{
public:
    ClimbUpStopCommandFactory() = default;
    virtual ~ClimbUpStopCommandFactory() {};
    Command* createCommand() { return new ClimbUpStopPlayerCommand();}
};

class DiedCommandFactory : public Factory
{
public:
    DiedCommandFactory() = default;
    virtual ~DiedCommandFactory() {};
    Command* createCommand() { return new DiedPlayerCommand();}
};

class HitGroundCommandFactory : public Factory
{
public:
    HitGroundCommandFactory() = default;
    virtual ~HitGroundCommandFactory() {};
    Command* createCommand() { return new HitGroundPlayerCommand();}
};

class JumpCommandFactory : public Factory
{
public:
    JumpCommandFactory() = default;
    virtual ~JumpCommandFactory() {};
    Command* createCommand() { return new JumpPlayerCommand();}
};

class ReviveCommandFactory : public Factory
{
public:
    ReviveCommandFactory() = default;
    virtual ~ReviveCommandFactory() {};
    Command* createCommand() { return new ReviviedPlayerCommand();}
};

class RunRightCommandFactory : public Factory
{
public:
    RunRightCommandFactory() = default;
    virtual ~RunRightCommandFactory() {};
    Command* createCommand() { return new RunRightPlayerCommand();}
};

class RunRightStopCommandFactory : public Factory
{
public:
    RunRightStopCommandFactory() = default;
    virtual ~RunRightStopCommandFactory() {};
    Command* createCommand() { return new RunRightStopPlayerCommand();}
};

class SlideCommandFactory : public Factory
{
public:
    SlideCommandFactory() = default;
    virtual ~SlideCommandFactory() {};
    Command* createCommand() { return new SlidePlayerCommand();}
};

class SwordAttackCommandFactory : public Factory
{
public:
    SwordAttackCommandFactory() = default;
    virtual ~SwordAttackCommandFactory() {};
    Command* createCommand() { return new SwordAttackPlayerCommand();}
};

class SwordStopCommandFactory : public Factory
{
public:
    SwordStopCommandFactory() = default;
    virtual ~SwordStopCommandFactory() {};
    Command* createCommand() { return new SwordStopPlayerCommand();}
};

class ThrowAttackCommandFactory : public Factory
{
public:
    ThrowAttackCommandFactory() = default;
    virtual ~ThrowAttackCommandFactory() {};
    Command* createCommand() { return new ThrowAttackPlayerCommand();}
};

class ThrowStopCommandFactory : public Factory
{
public:
    ThrowStopCommandFactory() = default;
    virtual ~ThrowStopCommandFactory() {};
    Command* createCommand() { return new ThrowStopPlayerCommand();}
};

class TopOfLadderCommandFactory : public Factory
{
public:
    TopOfLadderCommandFactory() = default;
    virtual ~TopOfLadderCommandFactory() {};
    Command* createCommand() { return new TopOfLadderPlayerCommand();}
};