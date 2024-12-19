#pragma once
#include "Character.h"
#include "Collide.h"
#include "HealthBar.h"

class Boss1 : public Character, public Collide
{
	int mRandomizer;
	HealthBar* mHB;
	Hitbox* mH;
	float mVelocityX;
	float mVelocityY;
	float mTimerInactive;
	float mTimerPattern1;
	float mTimerPattern2;
	float mTimerPattern3;
	float mTimerPattern4;

public:
	Boss1();

	void Update(float delta) override;

	void Shoot() override;

	void Randomize();

	void SetLifeBar(HealthBar* pHB);

	void Pattern1(float delta);

	void Pattern2(float delta);

	void Pattern3(float delta);

	void Pattern4(float delta);

	void Pattern5(float delta);

	// Hérité via Collide
	Hitbox GetHitbox() override;
	void OnCollide(Entity* e) override;
};

