#include "sprite.h"
#include "game.h"

Sprite::Sprite() {
	position.x = 0;
	position.y = 0;
	position.w = SPRITE_SIZE;
	position.h = SPRITE_SIZE;
	renderIndex = 0;
}

Sprite::Sprite(std::string p_id, int x, int y, int p_renderIndex) {
	position.x = x;
	position.y = y;
	position.w = SPRITE_SIZE;
	position.h = SPRITE_SIZE;
	renderIndex = p_renderIndex;
	id = p_id;
}

void Sprite::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
}

void Sprite::Render(SDL_Renderer* renderer, int textureIndex, SDL_Texture* sprite_textures) {
	SDL_Rect srect = { textureIndex * 32 , 0 , 32 , 32 };
	SDL_RenderCopy(renderer, sprite_textures, &srect, &position);
}

int Sprite::getRenderIndex() {
	return renderIndex;
}

void Sprite::setRenderIndex(int index) {
	renderIndex = index;
}

int Sprite::Update(Game* game) {
	std::cout << "Sprite Update" << std::endl;
	Render(game->getRenderer(), renderIndex, game->getSpriteSheet());
	return 0;
}