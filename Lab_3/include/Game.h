#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include "../include/Button.h"
#include "../include/LegoCommand.h"
#include "../include/PlasticCommand.h"
#include "../include/ConcreteCommand.h"
#include "../include/UndueCommand.h"
#include "../include/CommandButton.h"
#include "../include/RedoCommand.h"
#include "../include/BuildCommand.h"
#include "../include/ClayCommand.h"
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
    std::vector<CommandButton*> m_commandButtons;
    TTF_Font* m_font;
    MacroCommand m_commands;
    bool m_setUpText;
    bool m_brickIsCreated;
    std::vector<Brick*> m_bricks;
    void setUpWindow(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags);
    void setUpButtons();
    void handleOrderButtons();
    void handleActionButtons();
};