#pragma once
#include "Mob.h"

class Mob1 : public Mob
{
	int mRdm;
	float mTimerMove;

public:
	Mob1();

	void Shoot() override;

	void Update(float delta) override;
	Hitbox GetHitbox() override;
	void Pattern1(float delta);
};

