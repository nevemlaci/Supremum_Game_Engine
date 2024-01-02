#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "input.h"
#include "sprite.h"
#include <any>
#include <vector>
#include <map>
#include <windows.h>
#include "gameobject.h"
#include "audio.h"



class Game {
public:

	/// @brief Game constructor, if all parameters are left empty, the game will be created with default values.
	/// @param window_x Window x position
	/// @param window_y Window y position
	/// @param window_width Window width
	/// @param window_height Window height
	/// @param hide_console Wether to hide the console or not
	Game(
		int window_x=400,
		int window_y=400,
		int window_width=800,
		int window_height=480,
		bool hide_console=false
	);

	/// @brief Hides the console window
	void hideConsole();

	/// @brief The main loop of the game. Should be called after all objects are added.
	/// @return returns 0 on expected exit and 1 on unexpected exit
	int mainLoop();

	/// @brief adds an object to the game
	/// @param object_ptr Pointer to the object to be added. All objects that inherit from GameObject can be added.
	/// @return returns 0 on success
	int addObject(std::unique_ptr<GameObject> object);

	/// @brief The input handler of the game.
	/// @todo Rework
	std::unique_ptr<Input> input;

	/// @brief 
	/// @return returns the sprite sheet of the game
	SDL_Texture* getSpriteSheet();

	/// @brief 
	/// @return returns the SDL_Renderer* of the game 
	SDL_Renderer* getRenderer();

	/// @brief 
	/// @return returns a reference to the game's AudioManager
	AudioManager& Audio();

	std::unique_ptr<GameObject>& getObject(std::string id);
private:
	
	SDL_Window* window;

	SDL_Renderer* renderer;

	AudioManager audioManager;

	/// @brief The sprite sheet of the game.
	/// Used to store all textures used in the game to improve performance.
	SDL_Texture* spriteSheet;
	
	/// @brief The current SDL_Event of the game
	SDL_Event events;

	/// @brief  A map of all objects in the game.
	/// @todo fix memory leak when adding object of the same id
	std::map<std::string, std::unique_ptr<GameObject> > objects;


};