#pragma once
#include "../Others/Character.h"
#include "../Others/Collide.h"

class Mob1 : public Character, public Collide
{
	float mVelocityX;
	float mVelocityY;
	int mRdm;
	float mTimerMove;

public:
	Mob1();

	void Shoot() override;

	void Update(float delta) override;

	void Pattern1(float delta);

	Hitbox GetHitbox() override;
	void OnCollide(Entity* e) override;
};

