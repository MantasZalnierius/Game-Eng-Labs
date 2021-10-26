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

    setUpCommands();
}

void Game::setUpCommands()
{
    m_deathCommand = new DiedPlayerCommand();
    m_reviveCommand = new ReviviedPlayerCommand();
    m_swordAttackCommand = new SwordAttackPlayerCommand();
    m_throwAttackCommand = new ThrowAttackPlayerCommand();
    m_runRightCommand = new RunRightPlayerCommand();
    m_climbUpCommand = new ClimbUpPlayerCommand();
    m_climbDownCommand = new ClimbDownPlayerCommand();
    m_topOfLadderCommand = new TopOfLadderPlayerCommand();
    m_bottomOfLadderCommand = new BottomOfLadderPlayerCommand();
    m_slideCommand = new SlidePlayerCommand();
    m_hitGroundCommand = new HitGroundPlayerCommand();
    m_jumpCommand = new JumpPlayerCommand();
    m_runRightStopCommand = new RunRightStopPlayerCommand();
    m_throwStopCommand = new ThrowStopPlayerCommand();
    m_swordStopCommand = new SwordStopPlayerCommand();
    m_climbUpStopCommand = new ClimbUpStopPlayerCommand();
    m_climbDownStopCommand = new ClimbDownStopPlayerCommand();
}

void Game::handleEvents()
{
		SDL_Event eventHandlder;

        while(SDL_PollEvent( &eventHandlder ) != 0)
        {
            switch (eventHandlder.type)
            {

            case SDL_KEYDOWN:
            handleKeyPress(eventHandlder);
            break;

            case SDL_KEYUP:
            handleKeyRelease(eventHandlder);
            break;

            default:
                input.setCurrent(gpp::Events::Event::NONE);
                break;
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
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 0,0,0,255);
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

void Game::handleKeyPress(SDL_Event& m_eventHandlder)
{
    if(m_eventHandlder.key.keysym.sym == SDLK_m)
    {
        m_isRunning = false;
    }
    if (m_eventHandlder.key.keysym.sym == SDLK_d) 
    {
        m_deathCommand->execute(input);
    }
    // Revieved Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_r) 
    {
        m_reviveCommand->execute(input);
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
        m_swordAttackCommand->execute(input);
    }
    // Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_z)
    {
        m_swordAttackCommand->execute(input);
    }
    // Throw attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_x
        &&
        m_eventHandlder.key.keysym.sym == SDLK_RIGHT
        ||
        m_eventHandlder.key.keysym.sym == SDLK_RIGHT
        &&
        m_eventHandlder.key.keysym.sym == SDLK_x
        )
    {
        m_throwAttackCommand->execute(input);
    }
    // Throw Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_x)
    {
        m_throwAttackCommand->execute(input);
    }
    // Run Right
    else if (m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_runRightCommand->execute(input);
    }
    // Climb Up
    else if (m_eventHandlder.key.keysym.sym == SDLK_w)
    {
        m_climbUpCommand->execute(input);
    }
    // Climb Down
    else if (m_eventHandlder.key.keysym.sym == SDLK_s)
    {
        m_climbDownCommand->execute(input);
    }
    // Hit Bottom of Ladder Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_c)
    {
        m_bottomOfLadderCommand->execute(input);
    }
    // Hit Top of Ladder Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_t)
    {
        m_topOfLadderCommand->execute(input);
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
        m_jumpCommand->execute(input);
    }
    // Jump Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_SPACE)
    {
        m_jumpCommand->execute(input);
    }
    // Running Slide
    else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN)
    {
        m_slideCommand->execute(input);
    }
    // Hit Ground Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_h)
    {
        m_hitGroundCommand->execute(input);
    }

    // Jump Attack Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_h)
    {
        m_hitGroundCommand->execute(input);
    }

    // Jump Throw Attack Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_h)
    {
        m_hitGroundCommand->execute(input);
    }
}

void Game::handleKeyRelease(SDL_Event& m_eventHandlder)
{
    if (m_eventHandlder.key.keysym.sym == SDLK_z
    &&
    m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_runRightCommand->execute(input);
    }
    // Stop Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_z)
    {
        m_swordStopCommand->execute(input);
    }
    // Run and Stop Throw Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_x
        &&
        m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_runRightCommand->execute(input);
    }
    // Stop Throw Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_x)
    {
        m_throwStopCommand->execute(input);
    }
    // Stop Running Right
    else if (m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_runRightStopCommand->execute(input);
    }
    // Stop Slide
    else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN
        ||
        m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_runRightStopCommand->execute(input);
    }
    // Stop Moving Up
    else if (m_eventHandlder.key.keysym.sym == SDLK_w)
    {
        m_climbUpStopCommand->execute(input);
    }
    // Stop Moving Down
    else if (m_eventHandlder.key.keysym.sym == SDLK_s)
    {
        m_climbDownStopCommand->execute(input);
    }
}