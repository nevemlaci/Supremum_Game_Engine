#pragma once
#include "sprite.h"
#include "input.h"

class Player: public Sprite {
public:
	//Inherit the constructor from Sprite
	using Sprite::Sprite;
	/// <summary>
	/// Moves the player based on the input.
	/// </summary>
	/// <param name="input">Pointer of the input class.</param>
	int Update(Game* game);
protected:
	int velX;
	int velY;
};