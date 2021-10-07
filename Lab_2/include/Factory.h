#pragma once
#include <iostream>
#include <vector>
#include "bridge.h"

////// ABSTRACT FACTORY PATTERN 

class Brick
{
public:
    Brick() = default;
    virtual ~Brick() {}
    virtual void draw() = 0;
};

class Lego : public Brick
{
public:
    Lego() = default;
    Lego(DrawAPI* t_drawAPI) { this->m_drawAPI = t_drawAPI; }
    void draw() { m_drawAPI->draw(); }
private:
    DrawAPI* m_drawAPI;

};

class Plastic : public Brick
{
public:
    Plastic() = default;
    Plastic(DrawAPI* t_drawAPI) { this->m_drawAPI = t_drawAPI; }
    void draw() { m_drawAPI->draw(); }
private:
    DrawAPI* m_drawAPI;
};

class Concrete : public Brick
{
public:
    Concrete() = default;
    Concrete(DrawAPI* t_drawAPI) { this->m_drawAPI = t_drawAPI; }
    void draw() { m_drawAPI->draw(); }
private:
    DrawAPI* m_drawAPI;
};

class Factory
{
public:
    virtual std::vector<Brick*> getBricks(int t_numberOfBricks) = 0;
};

class LegoFactory : public Factory
{
public:
    LegoFactory() = default;
    virtual ~LegoFactory() {};
    std::vector<Brick*> getBricks(int t_numberOfBricks)
    {
        std::vector<Brick*> legoBricks;
        DrawAPI* drawAPI = new DrawAPIImple("LEGO BRICK");
        for (int i = 0; i < t_numberOfBricks; i++)
        {
            legoBricks.push_back(new Lego(drawAPI));
        }
        return legoBricks;
    }
};

class PlasticFactory : public Factory
{
public:
    PlasticFactory() = default;
    virtual ~PlasticFactory() {};
    std::vector<Brick*> getBricks(int t_numberOfBricks)
    {
        std::vector<Brick*> plasticBricks;
        DrawAPI* drawAPI = new DrawAPIImple("PLASTIC BRICK");
        for (int i = 0; i < t_numberOfBricks; i++)
        {
            plasticBricks.push_back(new Plastic(drawAPI));
        }
        return plasticBricks;
    }
};

class ConcreteFactory : public Factory
{
public:
    ConcreteFactory() = default;
    virtual ~ConcreteFactory() {};
    std::vector<Brick*> getBricks(int t_numberOfBricks)
    {
        std::vector<Brick*> concreteBricks;
        DrawAPI* drawAPI = new DrawAPIImple("CONCRETE BRICK");
        for (int i = 0; i < t_numberOfBricks; i++)
        {
            concreteBricks.push_back(new Concrete(drawAPI));
        }
        return concreteBricks;
    }
};

////// ABSTRACT FACTORY PATTERN 