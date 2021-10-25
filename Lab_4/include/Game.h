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
    void setUpTexture();
private:
    ~Game();

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    bool m_isRunning;
    bool m_setUpText;
    bool m_brickIsCreated;
    void setUpWindow(const char* t_title, unsigned int t_x, unsigned int t_y, unsigned int t_width, unsigned int t_height, Uint32 t_flags);
    Player m_player;
    AnimatedSprite m_animatedSprite;
    gpp::Events input;

    // PLAYER COMMANDS
    Command* m_deathCommand;
    Command* m_swordAttackCommand;
    Command* m_throwAttackCommand;
    Command* m_reviveCommand;
    Command* m_runRightCommand;
    Command* m_climbUpCommand;
    Command* m_climbDownCommand;
    Command* m_topOfLadderCommand;
    Command* m_bottomOfLadderCommand;
    Command* m_slideCommand;
    Command* m_jumpCommand;
    Command* m_hitGroundCommand;
    Command* m_swordStopCommand;
    Command* m_throwStopCommand;
    Command* m_runRightStopCommand;
    Command* m_climbUpStopCommand;
    Command* m_climbDownStopCommand;
    // PLAYER COMMANDS

    void handleKeyPress(SDL_Event& m_eventHandlder);
    void handleKeyRelease(SDL_Event& m_eventHandlder);
    void setUpCommands();
};