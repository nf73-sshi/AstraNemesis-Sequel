#pragma once
#include "../Scene.h"
#include <SFML/Graphics/Text.hpp>

class Level1 : public Scene
{
	float mCurrentTimer;
	float var;
	float mEndTimer;

	sf::Text textPlayerHP;
	sf::Text textMana;
public:
	void Init();
	void Update(float delta) override;
};

