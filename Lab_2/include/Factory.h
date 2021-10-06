#include <iostream>
#include <vector>

class Brick
{
    public:
        Brick() = default;
        Brick(std::string t_name) {m_name = t_name;}
        virtual ~Brick() {}
        virtual void draw() = 0;
        const std::string getName() {return m_name;}
    private:
    std::string m_name;
};

class Factory
{
    public:
        virtual std::vector<Brick*> getBricks(int t_numberOfBricks) = 0;
};

class Lego : public Brick
{
    public:
        Lego() = default;
        Lego(std::string t_name) : Brick(t_name) {}
        void draw() { std::cout << this->getName() << std::endl; }
};

class LegoFactory : public Factory
{
    public:
        LegoFactory() = default;
        virtual ~LegoFactory();
        std::vector<Brick*> getBricks(int t_numberOfBricks)
        {
            for(int i = 0; i < t_numberOfBricks; i++)
            {
                m_legoBricks.push_back(new Lego("LEGO BRICK"));
            }
            return m_legoBricks;
        }
    private:
        std::vector<Brick*> m_legoBricks;

};