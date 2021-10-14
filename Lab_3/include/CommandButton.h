#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "../include/MacroCommand.h"

class CommandButton
{
public:
    CommandButton() = default;
    CommandButton(SDL_Renderer* t_renderer,  TTF_Font* t_font, std::string t_name, float t_x, float t_y, float t_w, float t_h, Command* t_command) :
        m_renderer(t_renderer), m_font(t_font), m_name(t_name), m_x(t_x), m_y(t_y), m_w(t_w), m_h(t_w)
    {
        m_rectangle.x = m_x;
        m_rectangle.y = m_y;
        m_rectangle.w = m_w;
        m_rectangle.h = m_h;

        SDL_Surface* tempSurf = TTF_RenderText_Solid(t_font, m_name.c_str(), SDL_Color{255,255,255});

        m_text = SDL_CreateTextureFromSurface(m_renderer, tempSurf);

        SDL_QueryTexture(m_text, NULL, NULL, &m_textRect.w, &m_textRect.h);

        m_textRect.x = t_x + (m_rectangle.w / 2.0f) - (m_textRect.w / 2.0f);
        m_textRect.y = t_y + (m_rectangle.w / 2.0f) - (m_textRect.h / 2.0f);

        SDL_FreeSurface(tempSurf);

        m_command = t_command;
    }
    ~CommandButton() {}

    void render()
    {
        SDL_RenderDrawRect(m_renderer, &m_rectangle);
        SDL_RenderCopy(m_renderer, m_text, NULL, &m_textRect);
    }

    void clickUndu(MacroCommand* t_macro)
    {
        t_macro->undo();
    }

    void clickRedu(MacroCommand* t_macro)
    {
        t_macro->redu();
    }

    void clickBuild(MacroCommand* t_macro, std::vector<Brick*>& t_bricks)
    {
        t_macro->execute(t_bricks);
    }

    int getXPos() { return m_y; }

    int getYPos() { return m_x; }

    SDL_Rect getRect() { return m_rectangle; }

    int getOrderNumber() {return m_command->getCount();}

    std::string getName() {return m_name;}

private:
    SDL_Renderer* m_renderer;
    TTF_Font* m_font;
    SDL_Texture* m_text;
    SDL_Texture* m_counterText;
    float m_x;
    float m_y;
    float m_w;
    float m_h;
    SDL_Rect m_rectangle;
    SDL_Rect m_textRect;
    SDL_Rect m_counterRect;
    std::string m_name;
    Command* m_command;
    float m_textX;
    float m_textY;
    bool m_isText;
};