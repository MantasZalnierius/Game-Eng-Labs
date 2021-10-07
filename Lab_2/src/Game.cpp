#include "../include/Game.h"

Game::~Game()
{
    
}

Game::Game(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags)
{
    m_isdrawing = true;
    m_window = nullptr;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL FAILED TO INIT \n ERROR IS -> " << SDL_GetError();
    }

    m_window = SDL_CreateWindow(t_title, t_x, t_y, t_width, t_height, t_flags);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_window == nullptr) {
     std::cout << "WINDOW IS NULL \n ERROR IS -> " << SDL_GetError();
   }

    m_isRunning = true;

    Factory* legoFactory = new LegoFactory();
    Factory* plasticFactory = new PlasticFactory();
    Factory* concreteFactory = new ConcreteFactory();

    m_legoBricks = legoFactory->getBricks(10);
    m_plasticBricks = plasticFactory->getBricks(10);
    m_concreteBricks = concreteFactory->getBricks(10);
}

void Game::handleEvents()
{
   while(SDL_PollEvent( &m_eventHandlder ) != 0)
   {
       if(m_eventHandlder.type == SDL_KEYDOWN)
       {
            if(m_eventHandlder.key.keysym.sym == SDLK_x)
            {
                m_isRunning = false;
            }
       }
   }
}

void Game::update()
{
    while(this->isRunning())
    {
        this->handleEvents();
        this->render();
    }
    this->cleanUp();
}

void Game::render()
{
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(m_renderer);
    if (m_isdrawing)
    {
        for (int i = 0; i < m_legoBricks.size(); i++)
        {
            m_legoBricks.at(i)->draw();
        }
        for (int i = 0; i < m_plasticBricks.size(); i++)
        {
            m_plasticBricks.at(i)->draw();
        }
        for (int i = 0; i < m_concreteBricks.size(); i++)
        {
            m_concreteBricks.at(i)->draw();
        }
        m_isdrawing = false;
    }
}

bool Game::isRunning()
{
    return m_isRunning;
}

void Game::cleanUp()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Game::run()
{
    this->update();
}