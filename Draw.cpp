#include "Draw.h"

using namespace std;

Draw::Draw() {
}

Draw::~Draw() {
}


/**
* Write Text on screen.
*/
void Draw::text(SDL_Surface* surface, const string text, SDL_Color color,
                const int x, const int y, const int size, const int alpha) {
    TTF_Init();
    // Load font
    TTF_Font *font = TTF_OpenFont(Setting::FONT, size);
    // Set font, text and color
    SDL_Surface *surfaceText;
    if (alpha < 255) {
        surfaceText = TTF_RenderText_Solid(font, text.c_str(), color);
    } else {
        surfaceText = TTF_RenderText_Blended(font, text.c_str(), color);
    }
    // Set position
    SDL_Rect rectText = { x, y, 0, 0 };
    // Set alpha
    if (alpha < 255) {
        SDL_SetAlpha(surfaceText, SDL_RLEACCEL | SDL_SRCALPHA, alpha);
    }
    // Set to surface
    SDL_BlitSurface(surfaceText, NULL, surface, &rectText);
    SDL_FreeSurface(surfaceText);
    TTF_CloseFont(font);

}
