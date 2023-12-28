#pragma once
#include <string>

class Game;

class GameObject {
public:
	GameObject();
	GameObject(std::string p_id);

	virtual int Update(Game* game);

	std::string GetId();
protected:
	std::string id;
};