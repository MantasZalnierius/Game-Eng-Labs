#pragma once
#include <iostream>
#include "../include/proxy.h"


class DrawAPI
{
public:
    DrawAPI() = default;
    virtual ~DrawAPI() {};
    virtual void draw() = 0;
};


class DrawAPIImple : public DrawAPI
{
public:
    DrawAPIImple() = default;
    DrawAPIImple(std::string t_brickName) { m_grpahicProxy.setBrickName(t_brickName); };
    virtual ~DrawAPIImple() {};
    void draw()
    {
        m_grpahicProxy.draw();
    }
private:
    GraphicProxy m_grpahicProxy;
};