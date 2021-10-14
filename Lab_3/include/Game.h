#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include "../include/Button.h"
#include "../include/LegoCommand.h"
#include "../include/PlasticCommand.h"
#include "../include/ConcreteCommand.h"
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
    SDL_Event m_eventHandlder;
    std::vector<Button*> m_buttons;
    TTF_Font* m_font;
    MacroCommand m_commands;
};