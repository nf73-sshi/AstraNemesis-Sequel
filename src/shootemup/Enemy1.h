#pragma once
#include "Character.h"
#include "Collide.h"

class Enemy1 : public Character, public Collide
{
	float mVelocityX;
	float mVelocityY;
	float mTimer;
	float mTimer2;

public:
	Enemy1(const char* name, int hp, int damage, float speed, float shootingDelay);

	void Update(float delta) override;

	void Pattern1(float delta);

	void Pattern2(float delta);

	// Hérité via Collide
	Hitbox GetHitbox() override;
	void OnCollide(Entity*) override;
};

