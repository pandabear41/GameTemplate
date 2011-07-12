#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED


#include <SDL/SDL_gfxPrimitives.h>

#include "AbstractGameState.h"
#include "GameEngine.h"
#include "Draw.h"

class GameState: public AbstractGameState {
public:
	GameState();
	virtual ~GameState();

	void draw(SDL_Surface* surface);
	void clockTick();
	void keyPressed(SDLKey key);

private:
    int tickCount;
};


#endif // GAMESTATE_H_INCLUDED
