#include "GameState.h"
#include <iostream>
#include <stdio.h>

using namespace std;

GameState::GameState() {
    this->tickCount = 0;
    this->score = 0;

    // Set and load the image for the balls.
    this->lives = 3;
    this->balls = Draw::loadBMP("data/balls.bmp");
    Draw::setTransparent(this->balls, 0,0,0);


}

GameState::~GameState() {
    SDL_FreeSurface(this->balls);
    this->balls = NULL;
}

void GameState::clockTick() {
    tickCount++;
    this->score++;

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

	// white color
	SDL_Color color = { 255, 255, 255, 0 };

    // Draw Side Walls.
    Draw::filledRect(surface, 0, 0, 5, 240, 0xC0C0C0);
    Draw::filledRect(surface, 315, 0, 5, 240, 0xC0C0C0);

    // Draw Score.
    char buffer[15];
    sprintf(buffer,"%d",this->score);
    Draw::drawText(surface, buffer, color, "font/SFDIGIT.TTF", 7, 3, 25);

    int xB=320-7-12; //Room for wall and balls.
    for (int i = 1; i <= this->lives; i++) {
        Draw::drawSurface(surface, this->balls, xB, 3, 0, 0, 12, 12);
        xB-=14;
    }


}

void GameState::keyPressed(SDLKey key) {

}
