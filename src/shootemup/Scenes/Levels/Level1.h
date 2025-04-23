#pragma once
#include <SFML/Graphics/Text.hpp>
#include "Level.h"

class Level1 : public Level
{
	sf::Text textPlayerHP;
	sf::Text textMana;
public:
	void Init() override;
	void Update(float delta) override;
};

