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

    SDL_Texture* tex = getTexture(PLAYER_SPRITES);
    m_animatedSprite = AnimatedSprite(tex);
    m_player = Player(m_animatedSprite);

    setUpCommands();
}

void Game::setUpCommands()
{
    // SETS UP ALL FACTORIES
    m_commandFactoryMap.emplace("DEATH COMMAND FACTORY", new DiedCommandFactory());
    m_commandFactoryMap.emplace("REVIVE COMMAND FACTORY", new ReviveCommandFactory());
    m_commandFactoryMap.emplace("SWORD ATTACK COMMAND FACTORY", new SwordAttackCommandFactory());
    m_commandFactoryMap.emplace("THROW ATTACK COMMAND FACTORY", new ThrowAttackCommandFactory());
    m_commandFactoryMap.emplace("RUN RIGHT COMMAND FACTORY", new RunRightCommandFactory());
    m_commandFactoryMap.emplace("CLIMB UP COMMAND FACTORY", new ClimbUpCommandFactory());
    m_commandFactoryMap.emplace("CLIMB DOWN COMMAND FACTORY", new ClimbDownCommandFactory());
    m_commandFactoryMap.emplace("TOP OF LADDER COMMAND FACTORY", new TopOfLadderCommandFactory());
    m_commandFactoryMap.emplace("BOTTOM OF LADDER COMMAND FACTORY", new BottomOfLadderCommandFactory());
    m_commandFactoryMap.emplace("SLIDE COMMAND FACTORY", new SlideCommandFactory());
    m_commandFactoryMap.emplace("HIT GROUND COMMAND FACTORY", new HitGroundCommandFactory());
    m_commandFactoryMap.emplace("JUMP COMMAND FACTORY", new JumpCommandFactory());
    m_commandFactoryMap.emplace("RUN RIGHT STOP COMMAND FACTORY", new RunRightStopCommandFactory());
    m_commandFactoryMap.emplace("THROW ATTACK STOP COMMAND FACTORY", new ThrowStopCommandFactory());
    m_commandFactoryMap.emplace("SWORD ATTACK STOP COMMAND FACTORY", new SwordStopCommandFactory());
    m_commandFactoryMap.emplace("CLIMP UP STOP COMMAND FACTORY", new ClimbUpStopCommandFactory());
    m_commandFactoryMap.emplace("CLIMB DOWN STOP COMMAND FACTORY", new ClimbDownStopCommandFactory());

    // SETS UP ALL COMMANDS
    m_commandMap.emplace("DEATH COMMAND",                         m_commandFactoryMap.find("DEATH COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("REVIVE COMMAND",                       m_commandFactoryMap.find("REVIVE COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("SWORD ATTACK COMMAND",           m_commandFactoryMap.find("SWORD ATTACK COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("THROW ATTACK COMMAND",           m_commandFactoryMap.find("THROW ATTACK COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("RUN RIGHT COMMAND",                 m_commandFactoryMap.find("RUN RIGHT COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("CLIMB UP COMMAND",                   m_commandFactoryMap.find("CLIMB UP COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("CLIMB DOWN COMMAND",               m_commandFactoryMap.find("CLIMB DOWN COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("TOP OF LADDER COMMAND",         m_commandFactoryMap.find("TOP OF LADDER COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("BOTTOM OF LADDER COMMAND",   m_commandFactoryMap.find("BOTTOM OF LADDER COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("SLIDE COMMAND",                         m_commandFactoryMap.find("SLIDE COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("HIT GROUND COMMAND",               m_commandFactoryMap.find("HIT GROUND COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("JUMP COMMAND",                           m_commandFactoryMap.find("JUMP COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("RUN RIGHT STOP COMMAND",       m_commandFactoryMap.find("RUN RIGHT STOP COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("THROW ATTACK STOP COMMAND", m_commandFactoryMap.find("THROW ATTACK STOP COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("SWORD ATTACK STOP COMMAND", m_commandFactoryMap.find("SWORD ATTACK STOP COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("CLIMP UP STOP COMMAND",         m_commandFactoryMap.find("CLIMP UP STOP COMMAND FACTORY")->second->createCommand());
    m_commandMap.emplace("CLIMB DOWN STOP COMMAND",     m_commandFactoryMap.find("CLIMB DOWN STOP COMMAND FACTORY")->second->createCommand());
}


SDL_Texture* Game::getTexture(const char* const t_path)
{
    SDL_Texture* newTexture{ NULL };

    SDL_Surface* loadedSurface = IMG_Load(t_path);
    if (loadedSurface == NULL)
    {
        std::cout << "EEROR LOADING FILE PATH IS WRONG" << std::endl << IMG_GetError(); 
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
        if (newTexture == NULL)
        {
            std::cout << "SOMETHING WRONG WITH TEXTURE" << std::endl << SDL_GetError(); 
        }

        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
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
    m_player.render(m_renderer);
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
        m_commandMap.find("DEATH COMMAND")->second->execute(input);
    }
    // Revieved Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_r) 
    {
        m_commandMap.find("REVIVE COMMAND")->second->execute(input);
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
        m_commandMap.find("SWORD ATTACK COMMAND")->second->execute(input);
    }
    // Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_z)
    {
        m_commandMap.find("SWORD ATTACK COMMAND")->second->execute(input);
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
        m_commandMap.find("THROW ATTACK COMMAND")->second->execute(input);
    }
    // Throw Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_x)
    {
        m_commandMap.find("THROW ATTACK COMMAND")->second->execute(input);
    }
    // Run Right
    else if (m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_commandMap.find("RUN RIGHT COMMAND")->second->execute(input);
    }
    // Climb Up
    else if (m_eventHandlder.key.keysym.sym == SDLK_w)
    {
        m_commandMap.find("CLIMB UP COMMAND")->second->execute(input);
    }
    // Climb Down
    else if (m_eventHandlder.key.keysym.sym == SDLK_s)
    {
        m_commandMap.find("CLIMB DOWN COMMAND")->second->execute(input);
    }
    // Hit Bottom of Ladder Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_c)
    {
        m_commandMap.find("BOTTOM OF LADDER COMMAND")->second->execute(input);
    }
    // Hit Top of Ladder Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_t)
    {
        m_commandMap.find("TOP OF LADDER COMMAND")->second->execute(input);
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
        m_commandMap.find("JUMP COMMAND")->second->execute(input);
    }
    // Jump Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_SPACE)
    {
        m_commandMap.find("JUMP COMMAND")->second->execute(input);
    }
    // Running Slide
    else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN)
    {
        m_commandMap.find("SLIDE COMMAND")->second->execute(input);
    }
    // Hit Ground Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_h)
    {
        m_commandMap.find("HIT GROUND COMMAND")->second->execute(input);
    }

    // Jump Attack Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_h)
    {
       m_commandMap.find("HIT GROUND COMMAND")->second->execute(input);
    }

    // Jump Throw Attack Event
    else if (m_eventHandlder.key.keysym.sym == SDLK_h)
    {
        m_commandMap.find("HIT GROUND COMMAND")->second->execute(input);
    }
}

void Game::handleKeyRelease(SDL_Event& m_eventHandlder)
{
    if (m_eventHandlder.key.keysym.sym == SDLK_z
    &&
    m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_commandMap.find("RUN RIGHT COMMAND")->second->execute(input);
    }
    // Stop Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_z)
    {
        m_commandMap.find("SWORD ATTACK STOP COMMAND")->second->execute(input);
    }
    // Run and Stop Throw Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_x
        &&
        m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_commandMap.find("RUN RIGHT COMMAND")->second->execute(input);
    }
    // Stop Throw Attack
    else if (m_eventHandlder.key.keysym.sym == SDLK_x)
    {
        m_commandMap.find("THROW ATTACK STOP COMMAND")->second->execute(input);
    }
    // Stop Running Right
    else if (m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_commandMap.find("RUN RIGHT STOP COMMAND")->second->execute(input);
    }
    // Stop Slide
    else if (m_eventHandlder.key.keysym.sym == SDLK_DOWN
        ||
        m_eventHandlder.key.keysym.sym == SDLK_RIGHT)
    {
        m_commandMap.find("RUN RIGHT STOP COMMAND")->second->execute(input);
    }
    // Stop Moving Up
    else if (m_eventHandlder.key.keysym.sym == SDLK_w)
    {
        m_commandMap.find("CLIMP UP STOP COMMAND")->second->execute(input);
    }
    // Stop Moving Down
    else if (m_eventHandlder.key.keysym.sym == SDLK_s)
    {
        m_commandMap.find("CLIMB DOWN STOP COMMAND")->second->execute(input);
    }
}