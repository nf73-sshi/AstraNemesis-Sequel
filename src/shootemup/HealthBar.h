#pragma once
#include "SFML/Graphics.hpp"
#include "Health.h"
#include "Entity.h"

class HealthBar : public Entity
{
protected:
	sf::RectangleShape mHpBar;

public:
	HealthBar();

	void Update(float delta) override;
};

