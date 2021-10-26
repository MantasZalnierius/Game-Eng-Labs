#pragma once
#include <SDL_image.h>

//// PROXY PATTERN

class IGrpahic
{
public:
    IGrpahic() = default;
    virtual void draw(SDL_Texture* t_tex, SDL_Rect t_rect, SDL_Renderer* t_renderer, SDL_Rect t_rectOfImage) = 0;
};

class Graphic : public IGrpahic
{
public:
    Graphic() = default;
    ~Graphic() {};
    void draw(SDL_Texture* t_tex, SDL_Rect t_rect, SDL_Renderer* t_renderer, SDL_Rect t_rectOfImage) 
    { 
        SDL_RenderCopy(t_renderer, t_tex, &t_rectOfImage, &t_rect);
    }
};

class GraphicProxy : public IGrpahic
{
public:
    GraphicProxy() { this->m_graphic = 0; }
    ~GraphicProxy() { if (m_graphic) { delete m_graphic; } };
    void draw(SDL_Texture* t_tex, SDL_Rect t_rect, SDL_Renderer* t_renderer, SDL_Rect t_rectOfImage) 
    { 
        getInstance()->draw(t_tex, t_rect, t_renderer, t_rectOfImage); 
    }
private:
    Graphic* m_graphic;
    Graphic* getInstance(void)
    {
        if (!m_graphic)
        {
            m_graphic = new Graphic();
        }
        return m_graphic;
    };
};

//// PROXY PATTERN