#pragma once
#include <iostream>
#include <SDL_image.h>
#include "GraphicProxy.h"

//// BRIDGE PATTERN

class DrawAPI
{
public:
    DrawAPI() = default;
    virtual ~DrawAPI() {};
    virtual void drawSDLTexture(SDL_Texture* t_tex, SDL_Rect t_rect, SDL_Renderer* t_renderer, SDL_Rect t_rectOfImage) = 0;
};


class SdlDrawAPI : public DrawAPI
{
public:
    SdlDrawAPI() = default;
    virtual ~SdlDrawAPI() {};
    void drawSDLTexture(SDL_Texture* t_tex, SDL_Rect t_rect, SDL_Renderer* t_renderer, SDL_Rect t_rectOfImage)
    {
        m_grpahicProxy.draw(t_tex, t_rect, t_renderer, t_rectOfImage);
    }
private:
    GraphicProxy m_grpahicProxy;
};

//// BRIDGE PATTERN