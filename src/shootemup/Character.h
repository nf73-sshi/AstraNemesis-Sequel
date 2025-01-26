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
	float mShootingDelay;

	float mHitboxSize;

	float mTimerShoot;
	float mTimerInactive;
	float mTimerDelay;

	float mDefaultSpeed;
	float mDefaultScaleBall;
	int mDefaultDamage;
	float mDefaultSDelay;

	float mEndTimer;

public:
	Character(const char* name, int hp, int damage, float speed, float shootingDelay);

	sf::Vector2f GetPosition();

	float GetSpeed();
	void SetSpeed(float newSpeed);

	int GetDamage();

	float GetShootingDelay();
	void SetShootingDelay(float newSDelay);

	float GetDefaultSpeed();
	float GetDefaultScaleBall();
	int GetDefaultDamage();
	float GetDefaultSDelay();

	virtual void Shoot();

	virtual void Update(float delta);

};

