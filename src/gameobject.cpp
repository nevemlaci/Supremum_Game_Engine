#include "gameobject.h"
#include "game.h"

GameObject::GameObject(std::string p_id):id(p_id)
{
	this->id=p_id;
}

int GameObject::Update(Game& game) {
	return 0;
}

std::string GameObject::GetId() {
	return this->id;
}

