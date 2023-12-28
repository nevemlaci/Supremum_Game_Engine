#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>

///@todo rework input handling to be more flexible and less hardcoded

/// <summary>
/// Stores the state of the specified up, down, left and right keys.
/// </summary>
struct Keys {
	bool b_up, b_down, b_left, b_right;
};

/// <summary>
/// Stores the state of the mouse.
/// </summary>
struct Mouse {
	int x, y;
	bool leftclick;
	bool rightclick;
	bool middleclick;
};

class Input {
public:
	Input();
	/// <summary>
	/// Handles keypresses on the keyboard
	/// </summary>
	/// <param name="e"></param>
	void handleKeyboardInput(SDL_KeyboardEvent* e);
	/// <summary>
	/// Function to get keys pressed.
	/// </summary>
	/// <returns>Returns the state of the specified up, down, left and right keys.</returns>
	Keys getKeys();

	void setKeys(std::vector<SDL_Scancode> p_keys);
private:
	SDL_Scancode  up, down, left, right;
	Keys keys;
	Mouse mouse;
};