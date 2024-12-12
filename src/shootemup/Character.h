#pragma once
#include "Entity.h"

class Character : public Entity
{

protected:
	const char* mName;
	float mSpeed;
	int mDamage;
	float mShootingDelay;
	sf::Vector2f mPos;

public:
	Character(const char* name, int damage, float speed, float shootingDelay);

	sf::Vector2f GetPosition();

	float GetSpeed();

	int GetDamage();

	float GetShootingDelay();

	virtual void Update(float delta);
};

