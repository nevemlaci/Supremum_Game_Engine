#include "game.h"
#include <SDL_mixer.h>

/*
Game::Game() {
	window = SDL_CreateWindow("", 400, 400, 800, 480, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	spriteSheet = IMG_LoadTexture(renderer, "spritemap.png");
	input = Input();
}
*/

Game::Game(
	int window_x,
	int window_y,
	int window_width,
	int window_height,
	bool hide_console
) {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	window = SDL_CreateWindow("", window_x, window_y, window_width, window_height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	spriteSheet = IMG_LoadTexture(renderer, "spritemap.png");
	input = Input();
	if(hide_console) {
		std::cout << "Hiding console..." << std::endl;
		this->hideConsole();
	}
}

void Game::hideConsole() {
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_HIDE);
}

int Game::addObject(GameObject* object_ptr) {
	objects[object_ptr->GetId()] = object_ptr;
	return 0;
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
		for (auto object : objects) {
			object.second->Update(this);
		}
		SDL_RenderPresent(renderer);
	}
	return 1;
}

SDL_Texture* Game::getSpriteSheet() {
	return spriteSheet;
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}

AudioManager& Game::Audio() {
	return audioManager;
}