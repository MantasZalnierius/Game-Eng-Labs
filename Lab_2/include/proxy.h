#pragma once
#include <iostream>

//// PROXY PATTERN

class IGrpahic
{
public:
    IGrpahic() = default;
    virtual void draw() = 0;
};

class Graphic : public IGrpahic
{
public:
    Graphic(std::string t_brickName) { m_brickName = t_brickName; }
    ~Graphic() {};
    void draw() { std::cout << "I AM A " << this->m_brickName << std::endl; }
private:
    std::string m_brickName;
};

class GraphicProxy : public IGrpahic
{
public:
    GraphicProxy() { this->m_graphic = 0; }
    ~GraphicProxy() { if (m_graphic) { delete m_graphic; } };
    void draw() { getInstance()->draw(); }
    void setBrickName(std::string t_brickName) { m_brickName = t_brickName; }
private:
    Graphic* m_graphic;
    Graphic* getInstance(void)
    {
        if (!m_graphic)
        {
            m_graphic = new Graphic(m_brickName);
        }
        return m_graphic;
    };
    std::string m_brickName;
};

//// PROXY PATTERN