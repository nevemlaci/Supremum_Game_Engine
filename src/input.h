#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>

///@todo rework input handling to be more flexible and less hardcoded

/// @brief stores the mouse position and the state of the mouse buttons
struct Mouse {
	/// @brief x coordinate of the mouse
	int x;
	/// @brief y coordinate of the mouse
	int y;
	/// @brief true if the left mouse button is pressed, false if not
	bool leftclick;
	/// @brief true if the right mouse button is pressed, false if not
	bool rightclick;
	/// @brief true if the middle mouse button is pressed, false if not
	bool middleclick;
};

enum mousebutton {
	RIGHT, LEFT, MIDDLE
};

class Input {
public:
	Input();

	/// @brief updates the mouse position and mouse button states. 
	/// @note this function is called every frame and shouldn't be called manually.
	void updateMouse();

	/// @brief checks for a key in the keyState array
	/// @param key SDL_Scancode of the key to check. 
	/// @return returns true if the key is pressed, false if not
	/// @note Scancode reference: https://wiki.libsdl.org/SDL2/SDL_Scancode
	bool checkKey(SDL_Scancode key);

	/// @brief stores the mouse position and the state of the mouse buttons.
	/// See the Mouse struct definition for more information.
	Mouse mouse;

	
private:
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
};