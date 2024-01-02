#include "game.h"
#include <SDL_mixer.h>

/// @todo make a f.ing renderer class

Game::Game(
	int window_x,
	int window_y,
	int window_width,
	int window_height,
	bool hide_console
) :
	sdlinit(SDL_Init(SDL_INIT_EVERYTHING)),
	window(SDL_CreateWindow("", window_x, window_y, window_width, window_height, 0)),
	renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED)),
	audioManager(AudioManager::AudioManager()),
	inputManager(InputManager::InputManager())
{
	if (sdlinit != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}
	if (!window) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return;
	}
	if (!renderer) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return;
	}
	if(hide_console) {
		std::cout << "Hiding console..." << std::endl;
		this->hideConsole();
	}
}

void Game::hideConsole() {
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_HIDE);
}

int Game::addObject(std::unique_ptr<GameObject> object) {
	this->objects[object->GetId()] = std::move(object);
	return 0;
}

int Game::mainLoop() {

	while (true) {
		while (SDL_PollEvent(&(this->events))) {
			switch (this->events.type) {
				case SDL_QUIT:
					return 0;
					break;
			}
		}

		this->inputManager.updateMouse();

		SDL_RenderClear(this->renderer);

		for (auto& object : this->objects) {
			object.second->Update(*this); //this is the most heathen line of code I've ever written
		}

		SDL_RenderPresent(this->renderer);
	}
	return 1;
}

SDL_Texture* Game::getSpriteSheet() {
	return this->spriteSheet;
}

SDL_Renderer* Game::getRenderer() {
	return this->renderer;
}

AudioManager& Game::Audio() {
	return this->audioManager;
}

InputManager& Game::Input() {
	return this->inputManager;
}

std::unique_ptr<GameObject>& Game::getObject(std::string id) {
	return this->objects[id];
}