#pragma once
#include "Scene.h"

class Menu : public Scene
{
	sf::Vector2f mousePos;

public:
	void Init();
	void Update(float delta) override; 

};

