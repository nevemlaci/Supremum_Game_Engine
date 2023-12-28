#pragma once
#include <SDL.h>
#include "constants.h"
#include "gameobject.h"

class Game;

class Sprite:public GameObject{
public:
	/// <summary>
	/// Default constructor for the Sprite class. Sets the position to 0,0.
	/// </summary>
	Sprite(std::string p_id="", int x=0, int y=0, int p_renderIndex=0);

	void setPosition(int x , int y);
	/// <summary>
	/// Renders the sprite. Normally isn't called by the user and called once every frame in the main game loop.
	/// </summary>
	/// <param name="renderer">The renderer defined in the Game class</param>
	/// <param name="textureIndex">The texture index of the sprite.</param>
	/// <param name="sprite_textures">The sprite texture sheet.</param>
	void Render(SDL_Renderer* renderer, int textureIndex, SDL_Texture* sprite_textures);
	int getRenderIndex();
	/// <summary>
	/// Sets the render index of the sprite. This is used to determine where the renderer will look for the sprite on the spritesheet.
	/// </summary>
	/// <param name="index"></param>
	void setRenderIndex(int index);
	/// <summary>
	/// Ran on every frame in the game loop by default. Should be edited in child classes to add functionality.
	/// </summary>
	/// <returns>Returns 0 by default</returns>
	virtual int Update(Game* game);
protected:
	SDL_Rect position;
	int renderIndex;
};
