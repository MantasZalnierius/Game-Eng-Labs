#pragma once
#include <iostream>
class Brick
{
public:
    Brick() = default;
    virtual ~Brick() {}
    virtual std::string getName() = 0;
};

class Lego : public Brick
{
public:
    Lego() = default;
    Lego(std::string t_name) : m_name(t_name) { }
    std::string getName() {return m_name;}
private:
    std::string m_name;
};

class Plastic : public Brick
{
public:
    Plastic() = default;
    Plastic(std::string t_name) : m_name(t_name) { }
    std::string getName() {return m_name;}
private:
    std::string m_name;
};

class Concrete : public Brick
{
public:
    Concrete() = default;
    Concrete(std::string t_name) : m_name(t_name) { }
    std::string getName() {return m_name;}
private:
    std::string m_name;
};