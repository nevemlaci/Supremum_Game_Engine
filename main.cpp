#include <SDL.h>
#include <SDL_image.h>
#include "sprite.h"
#include <iostream>
#include "input.h"
#include "game.h"
#include "player.h"

/*
	To get started:
		There is a Sprite class that you can use to create a basic sprite.
		You can create a more complex object by inheriting from Sprite.

		To add a sprite you can use the addObeject method
		of the Game class.

		
*/
int main(int argc, char** argv) {
	Game game;

	Player sprite2(500,100);
	sprite2.setRenderIndex(1);
	game.addObject(&sprite2);
	game.mainLoop();
	return 0;
}