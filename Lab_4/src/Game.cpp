#include "Game.h"

Game::~Game()
{

}

Game::Game(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags)
{
    setUpWindow(t_title, t_x, t_y, t_width, t_height, t_flags);
    m_isRunning = true;

    int flags=IMG_INIT_JPG|IMG_INIT_PNG;

    int initted=IMG_Init(flags);

    if((initted&flags) != flags) {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        // handle error
    }

    SDL_Texture* tex = util::loadFromFile("include/assets/PlayerSpriteSheet.png", m_renderer);
    m_animatedSprite = AnimatedSprite(tex);
    m_player = Player(m_animatedSprite);
}

void Game::handleEvents()
{
   while(SDL_PollEvent( &m_eventHandlder ) != 0)
   {
       if(m_eventHandlder.type == SDL_KEYDOWN)
       {
           
            if(m_eventHandlder.key.keysym.sym == SDLK_m)
            {
                m_isRunning = false;
            }
            if (m_eventHandlder.key.keysym.sym == SDLK_d) {
                input.setCurrent(gpp::Events::Event::DIED_EVENT);
            }
            // Revieved Event
            else if (m_eventHandlder.key.keysym.sym == SDLK_r) {
                input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
            }
            // Running attack
            else if (m_eventHandlder.key.keysym.sym == SDLK_z
                &&
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                ||
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                &&
                m_eventHandlder.key.keysym.sym == SDLK_z
                )
            {
                input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
            }
            // Attack
            else if (m_eventHandlder.key.keysym.sym == SDLK_z)
            {
                input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
            }
            // Throw attack
            else if (m_eventHandlder.key.keysym.sym == SDLK_d
                &&
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                ||
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                &&
                m_eventHandlder.key.keysym.sym == SDLK_x
                )
            {
                input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
            }
            // Throw Attack
            else if (m_eventHandlder.key.keysym.sym == SDLK_x)
            {
                input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
            }
            // Run Right
            else if (m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
            {
                input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Climb Up
            else if (m_eventHandlder.key.keysym.sym == SDLK_UP)
            {
                input.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
            }
            // Climb Down
            else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN)
            {
                input.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
            }
            // Hit Bottom of Ladder Event
            else if (m_eventHandlder.key.keysym.sym == SDLK_c)
            {
                input.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
            }
            // Hit Top of Ladder Event
            else if (m_eventHandlder.key.keysym.sym == SDLK_t)
            {
                input.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
            }
            // Jump Run
            if (m_eventHandlder.key.keysym.sym == SDLK_SPACE
                &&
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                ||
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                &&
                m_eventHandlder.key.keysym.sym == SDLK_SPACE
                )
            {
                input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
            }
            // Jump Event
            else if (m_eventHandlder.key.keysym.sym == SDLK_SPACE)
            {
                input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
            }
            // Running Slide
            else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN
                && 
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                ||
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT
                && 
                m_eventHandlder.key.keysym.sym == SDLK_DOWN
                )
            {
                input.setCurrent(gpp::Events::Event::SLIDE_EVENT);
            }
            // Hit Ground Event
            else if (m_eventHandlder.key.keysym.sym == SDLK_h)
            {
                input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
            }

            // Jump Attack Event
            else if (m_eventHandlder.key.keysym.sym == SDLK_h)
            {
                input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
            }

            // Jump Throw Attack Event
            else if (m_eventHandlder.key.keysym.sym == SDLK_h)
            {
                input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
            }
       }
       else if(m_eventHandlder.type == SDL_KEYUP)
       {
           if (m_eventHandlder.key.keysym.sym == SDLK_z
                &&
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
            {
                input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Stop Attack
            else if (m_eventHandlder.key.keysym.sym == SDLK_z)
            {
                input.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
            }
            // Run and Stop Throw Attack
            else if (m_eventHandlder.key.keysym.sym == SDLK_x
                &&
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
            {
                input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Stop Throw Attack
            else if (m_eventHandlder.key.keysym.sym == SDLK_x)
            {
                input.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
            }
            // Stop Running Right
            else if (m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
            {
                input.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
            }
            // Stop Slide
            else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN
                &&
                m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
            {
                input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
            }
            // Stop Moving Up
            else if (m_eventHandlder.key.keysym.sym == SDLK_UP)
            {
                input.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
            }
            // Stop Moving Down
            else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN)
            {
                input.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
            }
       }
       else
       {
			input.setCurrent(gpp::Events::Event::NONE);
       }

       	m_player.handleInput(input);
   }
}

void Game::update()
{
    while(this->isRunning())
    {
        this->handleEvents();
        m_player.update();
        this->render();
    }
    this->cleanUp();
}

void Game::render()
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 255,255,255,255);
    m_player.getAnimatedSpriteFrame().render(0, 0, m_renderer);
    SDL_RenderPresent(m_renderer);
}

bool Game::isRunning()
{
    return m_isRunning;
}

void Game::cleanUp()
{
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
}

void Game::run()
{
    this->update();
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
}