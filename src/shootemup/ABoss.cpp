#include "ABoss.h"

ABoss::ABoss(const char* name, int hp, int damage, float speed, float shootingDelay, float atkSpeed, float scaleBall) : Character(name, hp, damage, speed, shootingDelay)
{
	srand(time(0));
	mAtkSpeed = atkSpeed;
	mScaleBall = scaleBall;
	mRandomizer = 0;
}

void ABoss::Randomize()
{
	mRandomizer = rand() % 101;
}

void ABoss::SetLifeBar(HealthBar* pHB)
{
	mHB = pHB;
}
