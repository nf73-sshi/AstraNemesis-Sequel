#pragma once
#include "Entity.h"
#include "../HealthMana/Health.h"

class Character : public Health, public Entity
{

protected:
	const char* mName;
	float mSpeed;
	float mScaleBall;
	int mDamage;
	float mShootingDelay;

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

	float GetSpeed();
	void SetSpeed(float newSpeed);

	int GetDamage();

	float GetShootingDelay();
	void SetShootingDelay(float newSDelay);
	void AddRemoveShootingDelay(float value);

	float GetDefaultSpeed();
	float GetDefaultScaleBall();
	int GetDefaultDamage();
	float GetDefaultSDelay();

	virtual void Shoot();

	virtual void Update(float delta);

};

