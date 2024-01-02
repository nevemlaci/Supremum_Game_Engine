#pragma once
#include <string>

class Game;

class GameObject {
public:
	/// @brief GameObject constructor
	/// @param p_id id of the game object
	GameObject(std::string p_id="NewGameObject");

	/// @brief Update function called every frame
	/// @param game pointer to the game @todo change to a reference
	/// @return 
	virtual int Update(Game& game);

	/// @brief get the id of the GameObject
	/// @return std::string id of the GameObject
	std::string GetId();
protected:
	std::string id;
};