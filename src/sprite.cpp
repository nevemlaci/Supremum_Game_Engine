#include "sprite.h"
#include "game.h"

Sprite::Sprite(std::string p_id, int x, int y, int p_renderIndex):
	position({x,y,SPRITE_SIZE,SPRITE_SIZE}),
	renderIndex(p_renderIndex),
	Sprite::GameObject(p_id)
{}

void Sprite::setPosition(int x, int y) {
	this->position.x = x;
	this->position.y = y;
}

void Sprite::Render(SDL_Renderer* renderer, int textureIndex, SDL_Texture* sprite_textures) {
	SDL_Rect srect = { textureIndex * 32 , 0 , 32 , 32 };
	SDL_RenderCopy(renderer, sprite_textures, &srect, &position);
}

int Sprite::getRenderIndex() {
	return this->renderIndex;
}

void Sprite::setRenderIndex(int renderIndex) {
	this->renderIndex = renderIndex;
}

int Sprite::Update(Game& game) {
	//std::cout << "Sprite Update" << std::endl;
	Render(game.getRenderer(), this->renderIndex, game.getSpriteSheet());
	return 0;
}