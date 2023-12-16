#include "player.h"
#include "game.h"
/*

Player::Player() {
	position.x = 0;
	position.y = 0;
	position.w = SPRITE_SIZE;
	position.h = SPRITE_SIZE;
	renderIndex = 0;
	velX = 0;
	velY = 0;
}
*/
/*

Player::Player(int x, int y) {
	position.x = x;
	position.y = y;
	position.w = SPRITE_SIZE;
	position.h = SPRITE_SIZE;
	renderIndex = 0;
	velX = 0;
	velY = 0;
}
*/

int Player::Update(Game* game) {
	Keys keys = game->input.getKeys();
	velY = - keys.b_up + keys.b_down;
	velX = keys.b_right - keys.b_left;
	position.x += (velX * PLAYER_SPEED);
	position.y += (velY * PLAYER_SPEED);
	return 0;
}