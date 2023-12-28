#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "input.h"
#include "sprite.h"
#include "player.h"
#include <any>
#include <vector>
#include <map>
#include <windows.h>
#include "gameobject.h"



class Game {
public:
	/// <summary>
	/// Default constructor. Usually this shouldn't be used. Use the advanced constructor instead.
	/// </summary>
	Game();

	/// <summary>
	/// Advanced constructor. It is used to initialize the game.
	/// </summary>
	/// <param name="window_x">Window X position</param>
	/// <param name="window_y">Window Yposition</param>
	/// <param name="window_width">Window width</param>
	/// <param name="window_height">Window height</param>
	/// <param name="hide_console">If the console window should be hidden or not.</param>
	Game(
		int window_x,
		int window_y,
		int window_width,
		int window_height,
		bool hide_console
	);

	/// <summary>
	/// The main loop of the game. Could be edited for customization.
	/// </summary>
	/// <returns>
	/// returns 0 on ecpected exit | returns 1 on unexpected exit
	/// </returns>
	int mainLoop();

	/// <summary>
	/// Adds an object to the game. Shouldn't be called on player.
	/// </summary>
	/// <param name="object_ptr">Pointer to the object to be added.
	/// The object must be the child of Sprite
	/// </param>
	/// <returns>
	/// returns 0 on success
	/// </returns>
	int addObject(GameObject* object_ptr);

	/// <summary>
	/// The input handler of the game. It is used to handle all input events.
	/// </summary>
	Input input;

	SDL_Texture* getSpriteSheet();
	SDL_Renderer* getRenderer();
private:
	
	SDL_Window* window;

	SDL_Renderer* renderer;

	/// <summary>
	/// The spritesheet of the game. It is used to store all sprite textures.It is used to reduce the number of textures loaded into the game.
	/// </summary>
	SDL_Texture* spriteSheet;
	
	/// <summary>
	/// The current SDL event.
	/// </summary>
	SDL_Event events;

	/// <summary>
	/// Array of GameObject pointers. It stores all objects in the game that are inheriting from GameObject.
	/// </summary>
	std::map<std::string,GameObject*> objects;
};