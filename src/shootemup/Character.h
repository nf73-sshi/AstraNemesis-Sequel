#pragma once
#include "Entity.h"
#include "Health.h"

class Character : public Entity, public Health
{

protected:
	sf::Vector2f mPos; 
	const char* mName;
	float mSpeed;
	int mDamage;
	float mShootingDelay;

public:
	Character(const char* name, int hp, int damage, float speed, float shootingDelay);

	sf::Vector2f GetPosition();

	float GetSpeed();

	int GetDamage();

	float GetShootingDelay();

	virtual void Update(float delta);
};

