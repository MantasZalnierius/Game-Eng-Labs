#include "../include/Game.h"

Game::~Game()
{

}

Game::Game(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags)
{
    setUpWindow(t_title, t_x, t_y, t_width, t_height, t_flags);
    setUpButtons();
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
           handleOrderButtons();
           handleActionButtons();
       }
   }
}

void Game::handleActionButtons()
{
    for(int i = 0; i < m_commandButtons.size(); i++)
    {
        if (m_eventHandlder.button.x > m_commandButtons.at(i)->getRect().x && m_eventHandlder.button.x < m_commandButtons.at(i)->getRect().x + m_commandButtons.at(i)->getRect().w)
        {
            if (m_eventHandlder.button.y > m_commandButtons.at(i)->getRect().y && m_eventHandlder.button.y < m_commandButtons.at(i)->getRect().y + m_commandButtons.at(i)->getRect().h)
            {
                if(m_commandButtons.at(i)->getName() == "UNDU")
                {
                    m_commandButtons.at(i)->clickUndu(&m_commands);
                }
                else if(m_commandButtons.at(i)->getName() == "REDU")
                {
                    m_commandButtons.at(i)->clickRedu(&m_commands);
                }
                else if(m_commandButtons.at(i)->getName() == "BUILD")
                {
                    m_commandButtons.at(i)->clickBuild(&m_commands, m_bricks);
                    m_brickIsCreated = true;
                }
                m_setUpText = true;
            }
        }
    }
}

void Game::handleOrderButtons()
{
    for(int i = 0; i < m_buttons.size(); i++)
    {
        if (m_eventHandlder.button.x > m_buttons.at(i)->getRect().x && m_eventHandlder.button.x < m_buttons.at(i)->getRect().x + m_buttons.at(i)->getRect().w)
        {
            if (m_eventHandlder.button.y > m_buttons.at(i)->getRect().y && m_eventHandlder.button.y < m_buttons.at(i)->getRect().y + m_buttons.at(i)->getRect().h)
            {
                m_buttons.at(i)->click(&m_commands);
            }
        }
    }

}

void Game::update()
{
    while(this->isRunning())
    {
        this->handleEvents();
        if(m_setUpText)
        {
            for(int i = 0; i < m_buttons.size(); i++)
            {
                m_buttons.at(i)->updateText();
                m_setUpText = false;
            }
        }
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

    for(int i = 0; i < m_commandButtons.size(); i++)
    {
        m_commandButtons.at(i)->render();
    }

    if(m_brickIsCreated)
    {
        for(int i = 0; i < m_bricks.size(); i++)
        {
            std::cout << m_bricks.at(i)->getName() << " WAS CREATED" << std::endl;
        }
        m_bricks.clear();
        m_brickIsCreated = false;
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

void Game::setUpButtons()
{
    m_buttons.push_back(new Button(m_renderer, m_font, "LEGO", 100, 100, 200, 200, new LegoCommand()));
    m_buttons.push_back(new Button(m_renderer, m_font, "PLASTIC", 100, 400, 200, 200, new PlasticCommand() ));
    m_buttons.push_back(new Button(m_renderer, m_font, "CONCRETE", 400, 100, 200, 200, new ConcreteCommand()));
    m_buttons.push_back(new Button(m_renderer, m_font, "CLAY", 400, 400, 200, 200, new ClayCommand()));

    m_buttons.at(0)->setUpCounter(m_renderer, m_font, "0", 180, 300);
    m_buttons.at(1)->setUpCounter(m_renderer, m_font, "0", 180, 600);
    m_buttons.at(2)->setUpCounter(m_renderer, m_font, "0", 480, 300);
    m_buttons.at(3)->setUpCounter(m_renderer, m_font, "0", 480, 600);


    m_commandButtons.push_back(new CommandButton(m_renderer, m_font, "UNDU", 800, 100, 200, 200, new UndueCommand()));
    m_commandButtons.push_back(new CommandButton(m_renderer, m_font, "REDU", 800, 400, 200, 200, new RedoCommand()));
    m_commandButtons.push_back(new CommandButton(m_renderer, m_font, "BUILD", 800, 700, 200, 200, new BuildCommand()));

    m_isRunning = true;
    m_setUpText = false;
    m_brickIsCreated = false;
}

void Game::setUpWindow(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    m_window = SDL_CreateWindow(t_title, t_x, t_y, t_width, t_height, t_flags);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_window == nullptr) {
     std::cout << "WINDOW IS NULL \n ERROR IS -> " << SDL_GetError();
    }
    m_font = TTF_OpenFont("times.ttf", 32);
}