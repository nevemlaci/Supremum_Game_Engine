#include "input.h"

InputManager::InputManager()
{
	this->mouse.leftclick = this->mouse.rightclick = this->mouse.middleclick = false;
}

void InputManager::updateMouse() {
	Uint32 mouseState = SDL_GetMouseState(&(this->mouse.x), &(this->mouse.y));
	
	if(mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		this->mouse.leftclick = true;
		std::cout << "leftclick" << std::endl;
	} else {
		this->mouse.leftclick = false;
	}
	if(mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
		this->mouse.rightclick = true;
	} else {
		this->mouse.rightclick = false;
	}
	if(mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE)) {
		this->mouse.middleclick = true;
	} else {
		this->mouse.middleclick = false;
	}
}

bool InputManager::checkKey(SDL_Scancode key) {
	return this->keyState[key];
}
