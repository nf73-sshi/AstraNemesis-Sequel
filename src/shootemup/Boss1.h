#pragma once
#include "Character.h"
#include "Collide.h"

class Boss1 : public Character, public Collide
{
	int mRandomizer;
	float mVelocityX;
	float mVelocityY;
	float mTimerInactive;
	float mTimerPattern1;
	float mTimerPattern2;
	float mTimerPattern3;

public:
	Boss1();

	void Update(float delta) override;

	void Randomize();

	void Shoot() override;

	void Pattern1(float delta);

	void Pattern2(float delta);

	void Pattern3(float delta);

	// Hérité via Collide
	Hitbox GetHitbox() override;
	void OnCollide(Entity* e) override;
};

