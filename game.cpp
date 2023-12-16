#include "game.h"

Game::Game() {
	window = SDL_CreateWindow("", 400, 400, 800, 480, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	spriteSheet = IMG_LoadTexture(renderer, "spritemap.png");
	input = Input();
	//HWND console = GetConsoleWindow();
	//ShowWindow(console, SW_HIDE);

}

int Game::addObject(Sprite* object_ptr) {
		objects.push_back(object_ptr);
		return 0;
}

void Game::addPlayer(Player p_player) {
	player = p_player;
}

int Game::mainLoop() {
	while (true) {
		while (SDL_PollEvent(&events)) {
			switch (events.type) {
			case SDL_KEYDOWN:
				input.handleKeyboardInput(&events.key);
				break;
			case SDL_KEYUP:
				input.handleKeyboardInput(&events.key);
				break;
			case SDL_QUIT:
				return 0;
				break;
			}
		}
		SDL_RenderClear(renderer);
		for (Sprite* sprite : objects) {
			sprite->Update(this);
			sprite->Render(renderer, sprite->getRenderIndex(), spriteSheet);
		}
		SDL_RenderPresent(renderer);
	}
	return 1;
}