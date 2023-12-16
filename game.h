#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "input.h"
#include "sprite.h"
#include "player.h"
#include <any>
#include <vector>
#include <windows.h>

class Game {
public:
	Game();
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
	int addObject(Sprite* object_ptr);
	/// <summary>
	/// Adds a player to the game.
	/// </summary>
	/// <param name="p_player">
	/// The player to be added.
	/// NULL should be passed if no player is needed, or if a custom player class is used.
	/// </param>
	void addPlayer(Player p_player);

	/// <summary>
	/// The input handler of the game. It is used to handle all input events.
	/// </summary>
	Input input;
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
	/// The player of the game. Not necessary to be used. 
	/// </summary>
	Player player;
	/// <summary>
	/// Array of Sprite pointers. It stores all objects in the game that are inheriting from Sprite.
	/// </summary>
	std::vector<Sprite*> objects;
};