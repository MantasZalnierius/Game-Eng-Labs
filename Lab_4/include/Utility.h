#ifndef UTILITY_H
#define UTILITY_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

namespace util
{
    static inline SDL_Texture* loadFromFile(const char* const t_path, SDL_Renderer* t_renderer)
    {
        SDL_Texture* newTexture{ NULL };

        SDL_Surface* loadedSurface = IMG_Load(t_path);
        if (loadedSurface == NULL)
        {
            std::cout << "EEROR LOADING FILE PATH IS WRONG" << std::endl << IMG_GetError(); 
        }
        else
        {
            newTexture = SDL_CreateTextureFromSurface(t_renderer, loadedSurface);
            if (newTexture == NULL)
            {
                std::cout << "SOMETHING WRONG WITH TEXTURE" << std::endl << SDL_GetError(); 
            }

            SDL_FreeSurface(loadedSurface);
        }

        return newTexture;
    }

    static const char* const PLAYER_SPRITES	= "assets\\PlayerSpriteSheet.png";
    static const char* const ERROR_SPRITES  = "assets\\ErrorSpriteSheet.png";
}

#endif