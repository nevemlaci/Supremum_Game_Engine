#pragma once
#include "sprite.h"
#include "input.h"

class Player: public Sprite {
public:
	Player();
	Player(int x, int y);
	/// <summary>
	/// Moves the player based on the input.
	/// </summary>
	/// <param name="input">Pointer of the input class.</param>
	int Update(Game* game);
protected:
	int velX;
	int velY;
};