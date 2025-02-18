#pragma once
#include "../Others/Entity.h"

class Background : public Entity
{
	sf::Vector2f mPos;
public:
	Background();
	void Update(float delta) override;

};

