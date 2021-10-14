#include "../include/Game.h"

Game::~Game()
{

}

Game::Game(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    m_window = SDL_CreateWindow(t_title, t_x, t_y, t_width, t_height, t_flags);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_window == nullptr) {
     std::cout << "WINDOW IS NULL \n ERROR IS -> " << SDL_GetError();
    }
    m_font = TTF_OpenFont("times.ttf", 32);

    m_buttons.push_back(new Button(m_renderer, m_font, "LEGO", 100, 100, 200, 200, new LegoCommand()));
    m_buttons.push_back(new Button(m_renderer, m_font, "PLASTIC", 100, 400, 200, 200, new PlasticCommand() ));
    m_buttons.push_back(new Button(m_renderer, m_font, "CONCRETE", 400, 100, 200, 200, new ConcreteCommand()));


    m_buttons.push_back(new Button(m_renderer, m_font, "UNDUE", 800, 100, 200, 200));
    m_buttons.push_back(new Button(m_renderer, m_font, "REDUE", 800, 400, 200, 200));
    m_buttons.push_back(new Button(m_renderer, m_font, "BUILD", 800, 700, 200, 200));

    m_isRunning = true;
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
       else if(m_eventHandlder.type == SDL_MOUSEBUTTONDOWN)
       {
            for(int i = 0; i < m_buttons.size(); i++)
            {
                if (m_eventHandlder.button.x > m_buttons.at(i)->getRect().x && m_eventHandlder.button.x < m_buttons.at(i)->getRect().x + m_buttons.at(i)->getRect().w)
                {
                    if (m_eventHandlder.button.y > m_buttons.at(i)->getRect().y && m_eventHandlder.button.y < m_buttons.at(i)->getRect().y + m_buttons.at(i)->getRect().h)
                    {
                        std::cout << "I AM HERE";
                    }
                }
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
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255,255,255,255);

    for(int i = 0; i < m_buttons.size(); i++)
    {
        m_buttons.at(i)->render();
    }

    SDL_RenderPresent(m_renderer);
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