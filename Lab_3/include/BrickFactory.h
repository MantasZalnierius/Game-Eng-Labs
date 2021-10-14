#pragma once
#include <iostream>
#include "../include/Brick.h"

class Factory
{
public:
    virtual Brick* CreateBrick() = 0;
};

class LegoFactory : public Factory
{
public:
    LegoFactory() = default;
    virtual ~LegoFactory() {};
    Brick* CreateBrick() { return new Lego("LEGO");}
};

class PlasticFactory : public Factory
{
public:
    PlasticFactory() = default;
    virtual ~PlasticFactory() {};
    Brick* CreateBrick() { return new Lego("PLASTIC");}
};

class ConcreteFactory : public Factory
{
public:
    ConcreteFactory() = default;
    virtual ~ConcreteFactory() {};
    Brick* CreateBrick() { return new Lego("CONCRETE");}
};