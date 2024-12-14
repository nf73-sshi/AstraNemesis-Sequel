#pragma once
#include "Character.h"
#include "Collide.h"

class Boss1 : public Character, public Collide
{
	float mVelocityX;
	float mVelocityY;
	float mTimerPattern1;
	float mTimerPattern2;

public:
	Boss1(const char* name, int hp, int damage, float speed, float shootingDelay);

	void Update(float delta) override;

	void Shoot() override;

	void Pattern1(float delta);

	void Pattern2(float delta);

	// Hérité via Collide
	Hitbox GetHitbox() override;
	void OnCollide(Entity* e) override;
};

