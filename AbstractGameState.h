#ifndef ABSTRACTGAMESTATE_H
#define ABSTRACTGAMESTATE_H

#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


class AbstractGameState {
public:
    AbstractGameState();
    virtual ~AbstractGameState();

    virtual void clockTick();
    virtual void draw(SDL_Surface* surface);
    virtual void keyPressed(SDLKey key);
    /**
    * Convert Int to String.
    */
    static const std::string intToString(const int number);


    AbstractGameState* state;
    SDL_Event event;
    bool done;
protected:
    SDL_Surface* background;
    bool reDraw;
};

#endif // ABSTRACTGAMESTATE_H
