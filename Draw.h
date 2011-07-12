#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <SDL/SDL_gfxPrimitives.h>
#include <string>
#include "Setting.h"

class Draw {
public:
    Draw();
    virtual ~Draw();

    /**
    * Print text on screen.
    * Set color, position, size, alpha.
    */
    static void text(SDL_Surface* surface, const std::string text,
    SDL_Color color, const int x = 0, const int y = 0, const int size =
    30, const int alpha = 255);

};


#endif // DRAW_H_INCLUDED
