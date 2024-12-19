#pragma once
#include "Entity.h"
#include "Health.h"

class Character : public Health, public Entity
{

protected:
	sf::Vector2f mPos; 
	const char* mName;
	float mSpeed;
	float mScaleBall;
	int mDamage;
	float mTimerShoot;
	float mTimerInactive;
	float mShootingDelay;
	float mTimerDelay;

	float mEndTimer;

public:
	Character(const char* name, int hp, int damage, float speed, float shootingDelay);

	sf::Vector2f GetPosition();

	float GetSpeed();

	int GetDamage();

	float GetShootingDelay();

	virtual void Shoot();

	virtual void Update(float delta);

};

