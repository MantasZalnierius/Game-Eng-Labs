#pragma once
#include <SDL.h>
#include <iostream>
#include "../include/Factory.h"

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
    bool m_isdrawing;
    SDL_Event m_eventHandlder;
    std::vector<Brick*> m_legoBricks;
    std::vector<Brick*> m_plasticBricks;
    std::vector<Brick*> m_concreteBricks;
};