#pragma once
#include <SDL.h>
#include <iostream>

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
private:
    ~Game();
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    bool m_isRunning;
    SDL_Event m_eventHandlder;
};