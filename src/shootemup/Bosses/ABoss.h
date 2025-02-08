#pragma once
#include "../Others/Character.h"
#include "../Others/Collide.h"

class HealthBar;

class ABoss : public Character, public Collide
{
protected:
	int mRandomizer;
	HealthBar* mHB;

	float mScaleBall;
	float mAtkSpeed;

public:
	ABoss(const char* name, int hp, int damage, float speed, float shootingDelay, float atkSpeed, float scaleBall);

	virtual void Update(float delta);

	virtual void Shoot() = 0;

	void Randomize();

	void SetLifeBar(HealthBar* pHB);

	virtual Hitbox GetHitbox() = 0;
	virtual void OnCollide(Entity* e);
};

