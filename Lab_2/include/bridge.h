#pragma once
#include <iostream>
#include "../include/proxy.h"

//// BRIDGE PATTERN

class DrawAPI
{
public:
    DrawAPI() = default;
    virtual ~DrawAPI() {};
    virtual void draw() = 0;
};


class OpenGLDrawImple : public DrawAPI
{
public:
    OpenGLDrawImple() = default;
    OpenGLDrawImple(std::string t_brickName) { m_grpahicProxy.setBrickName(t_brickName); };
    virtual ~OpenGLDrawImple() {};
    void draw()
    {
        m_grpahicProxy.draw();
    }
private:
    GraphicProxy m_grpahicProxy;
};

class SdlDrawImple : public DrawAPI
{
public:
    SdlDrawImple() = default;
    SdlDrawImple(std::string t_brickName) { m_grpahicProxy.setBrickName(t_brickName); };
    virtual ~SdlDrawImple() {};
    void draw()
    {
        m_grpahicProxy.draw();
    }
private:
    GraphicProxy m_grpahicProxy;
};

class VulkanDrawImple : public DrawAPI
{
public:
    VulkanDrawImple() = default;
    VulkanDrawImple(std::string t_brickName) { m_grpahicProxy.setBrickName(t_brickName); };
    virtual ~VulkanDrawImple() {};
    void draw()
    {
        m_grpahicProxy.draw();
    }
private:
    GraphicProxy m_grpahicProxy;
};

//// BRIDGE PATTERN