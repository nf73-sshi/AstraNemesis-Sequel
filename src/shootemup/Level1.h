#pragma once
#include "Scene.h"
class Level1 : public Scene
{
	float mCurrentTimer;
	float var;
	sf::Vector2f playerPos;
	Entity* mCurrentPlayer;

public:
	void Init();
	void Update(float delta) override;
	void GetPosition(Entity* pPlayer); 
};

