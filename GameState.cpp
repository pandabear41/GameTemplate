#include "GameState.h"
#include <iostream>

using namespace std;

GameState::GameState() {
    this->tickCount=0;
}

GameState::~GameState() {

}

void GameState::clockTick() {
    tickCount++;

    this->reDraw = true;
}

void GameState::draw(SDL_Surface* surface) {

	// To avoid redrawing every tick when nothing have actually changed.
	if (!this->reDraw) {
		return;
	} else {
		this->reDraw = false;
	}

    SDL_FillRect(surface,NULL, 0x000000);

	// white
	SDL_Color color = { 255, 255, 255, 0 };

    //Draw Side Walls.
    Draw::filledRect(surface, 0, 0, 5, 240, 0xC0C0C0);
    Draw::filledRect(surface, 315, 0, 5, 240, 0xC0C0C0);



}

void GameState::keyPressed(SDLKey key) {

}
