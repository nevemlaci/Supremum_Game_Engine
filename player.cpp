#include "player.h"
#include "game.h"


int ExamplePlayer::Update(Game* game) {
	Keys keys = game->input.getKeys();
	velY = - keys.b_up + keys.b_down;
	velX = keys.b_right - keys.b_left;
	position.x += (velX * PLAYER_SPEED);
	position.y += (velY * PLAYER_SPEED);
	return 0;
}