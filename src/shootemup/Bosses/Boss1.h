#pragma once
#include "../Others/Character.h"
#include "../Others/Collide.h"
#include "../HealthMana/HealthBar.h"
#include "ABoss.h" 

class Boss1 : public ABoss 
{
	float mSpeedBoost;
	float mTimerPattern1;
	float mTimerPattern2;
	float mTimerPattern3;
	float mTimerPattern4;
	float mTimerPattern5;

public:
	Boss1();

	void Update(float dt) override;

	void Shoot() override;

	void PatternGlobal(float delta);

	void PatternSweepBall(float delta);

	void PatternBigBall(float delta);

	void PatternSpawnMobs(float delta);

	void PatternTripleBall(float delta);

	std::vector<Hitbox>GetHitboxes() override;
	void OnCollide(Entity* e) override;
};

