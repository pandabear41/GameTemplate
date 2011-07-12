#include "IntroState.h"

using namespace std;

IntroState::IntroState() {


}

IntroState::~IntroState() {

}

void IntroState::draw(SDL_Surface* surface) {

	// To avoid redrawing every tick when nothing have actually changed.
	if (!this->reDraw) {
		return;
	} else {
		this->reDraw = false;
	}

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;

	// white
	SDL_Color color = { 255, 255, 255, 0 };

	// Print out menu
	Draw::text(surface, "Rebellious Tower Defence", color, 50, 50, 100, 100);
	Draw::text(surface, "Play Game", color, 100, 200, 90, 100);
	Draw::text(surface, "Highscore", color, 100, 300, 90, 100);
	Draw::text(surface, "Help", color, 100, 400, 90, 100);
	Draw::text(surface, "Information", color, 100, 500, 90, 100);
	Draw::text(surface, "Exit", color, 100, 600, 90, 100);
	Draw::text(surface, "Make your own map", color, 740, 640, 30, 100);


}

void IntroState::keyPressed(SDLKey key) {
	this->reDraw = true;


}
