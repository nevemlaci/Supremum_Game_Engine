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
		
		There is an example player class that inherits from Sprite.
		
*/
int main(int argc, char** argv) {

	Game game(100, 100, 700, 700, true);
	game.addObject(new Player(100, 100, 1));
	game.mainLoop();
	return 0;
}