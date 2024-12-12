#pragma once
#include "Character.h"

class Enemy1 : public Character
{
	sf::Vector2f mPos;
	float mSPeed;
	float mVelocityX;
	float mVelocityY;
	float mTimer;
	float mTimer2;

public:
	Enemy1(const char* name, int damage, float speed, float shootingDelay);

	void Update(float delta) override;

	void Pattern1(float delta);

	void Pattern2(float delta);
};

