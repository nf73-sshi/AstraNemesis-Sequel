#pragma once
#include "Scene.h"
class Level : public Scene
{
	float mCurrentTimer;
	float var;
	sf::Vector2f pos;
	Entity* mCurrentPlayer;

public:
	void Init();
	void Update(float delta) override;
	void GetPosition(Entity* pPlayer); 
};

