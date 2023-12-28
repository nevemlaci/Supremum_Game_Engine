#include "input.h"

Input::Input() {
	up = SDL_SCANCODE_W;
	down = SDL_SCANCODE_S;
	left = SDL_SCANCODE_A;
	right = SDL_SCANCODE_D;

	keys.b_up = false;
	keys.b_down = false;
	keys.b_left = false;
	keys.b_right = false;

	mouse.leftclick = mouse.rightclick = mouse.middleclick = false;
}

void Input::handleKeyboardInput(SDL_KeyboardEvent* e) {
	if (e->type == SDL_KEYDOWN) {
		if (e->keysym.scancode == up) keys.b_up = true;
		if (e->keysym.scancode == down) keys.b_down = true;
		if (e->keysym.scancode == left) keys.b_left = true;
		if (e->keysym.scancode == right) keys.b_right = true;
	}
	if (e->type == SDL_KEYUP) {
		if (e->keysym.scancode == up) keys.b_up = false;
		if (e->keysym.scancode == down) keys.b_down = false;
		if (e->keysym.scancode == left) keys.b_left = false;
		if (e->keysym.scancode == right) keys.b_right = false;
	}
	std::cout << "up: " << keys.b_up << " down: " << keys.b_down << " left: " << keys.b_left << " right: " << keys.b_right << std::endl;
}

Keys Input::getKeys() {
	return keys;
}

void Input::setKeys(std::vector<SDL_Scancode> p_keys) {
	up = p_keys[0];
	down = p_keys[1];
	left = p_keys[2];
	right = p_keys[3];
}
