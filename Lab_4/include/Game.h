#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "AnimatedSprite.h"
#include "Player.h"
#include "Utility.h"
#include "Events.h"
#include "CommandIncludes.h"
#include <map>

class Game
{
public:
    Game() = default;
    Game(const char* title, unsigned int x, unsigned int y, unsigned int width, unsigned int height, Uint32 flags);
    void handleEvents();
    void update();
    void render();
    bool isRunning();
    void cleanUp();
    void run();
private:
    ~Game();

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    bool m_isRunning;
    bool m_setUpText;
    bool m_brickIsCreated;
    void setUpWindow(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags);

    SDL_Texture* getTexture(const char* const t_path);
    Player m_player;
    AnimatedSprite m_animatedSprite;
    gpp::Events input;

    void handleKeyPress(SDL_Event& m_eventHandlder);
    void handleKeyRelease(SDL_Event& m_eventHandlder);
    void setUpCommands();

    std::map<std::string, Command*> m_commandMap;
};