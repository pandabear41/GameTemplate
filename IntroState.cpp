#include "IntroState.h"
#include "GameState.h"
#include <iostream>
using namespace std;

IntroState::IntroState() {
    this->textAlpha=255;
    this->tickCount=0;
    this->forward = false;
}

IntroState::~IntroState() {

}

void IntroState::clockTick() {
    tickCount++;
    if (forward) {
        this->textAlpha += 10;
    } else {
        this->textAlpha -= 10;
    }
    if (this->textAlpha >= 255) {
        this->textAlpha=254;
        this->forward = false;
    } else if (this->textAlpha <= 0) {
        this->textAlpha=0;
        this->forward = true;
    }
    this->reDraw = true;
}

void IntroState::draw(SDL_Surface* surface) {

	// To avoid redrawing every tick when nothing have actually changed.
	if (!this->reDraw) {
		return;
	} else {
		this->reDraw = false;
	}

    SDL_FillRect(surface,NULL, 0x000000);

	// white
	SDL_Color color = { 255, 255, 255, 0 };

	// Print out menu
	Draw::text(surface, "Breakout", color, 160-80, 15, 40, 255);
    Draw::text(surface, "Press Any Button", color, 160-120, 160, 30, this->textAlpha);
    Draw::text(surface, "To Start", color, 160-60, 190, 30, this->textAlpha);

}

void IntroState::keyPressed(SDLKey key) {
    this->state = new GameState();
}
