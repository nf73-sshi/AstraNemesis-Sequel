#pragma once
#include "../Others/Character.h"
#include "../Others/Collide.h"
#include "../HealthMana/HealthBar.h"
#include "ABoss.h" 

class Boss1 : public ABoss 
{
	float mSpeedBoost;

	float mVelocityX;
	float mVelocityY;
	float mTimerInactive;
	float mTimerPattern1;
	float mTimerPattern2;
	float mTimerPattern3;
	float mTimerPattern4;
	float mTimerPattern5;

public:
	Boss1();

	void Update(float delta) override;

	void Shoot() override;

	void Pattern1(float delta);

	void Pattern2(float delta);

	void Pattern3(float delta);

	void Pattern4(float delta);

	void Pattern5(float delta);

	// Hérité via Collide
	Hitbox GetHitbox() override;
	std::vector<Hitbox>GetHitboxes() override;
	void OnCollide(Entity* e) override;
};

