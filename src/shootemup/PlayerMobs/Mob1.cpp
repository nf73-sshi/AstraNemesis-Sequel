#include "Mob1.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "Player.h"
#include "../Important/GameManager.h"

Mob1::Mob1() : Mob("Mob1", 30, 1, 300, 0.5)
{
	mDrawPriority = 6;
	mTimerMove = 0;
	CreateSprite("MobsTile", 0, 0, 64, 64);
	mRdm = 0;

	manaReward = 3;
}


void Mob1::Update(float delta)
{
	if (mTimerInactive < 1.5)
	{
		this->move(0, 310 * delta);
		mTimerInactive += delta;
		return;
	}

	Mob::Update(delta);

	Pattern1(delta);
}

void Mob1::Pattern1(float delta)
{
	if (mTimerMove >= 1)
	{
		mRdm = rand() % 2;

		if(mRdm)
			mVelocityX = -mVelocityX;

		mTimerMove = 0;
	}

	if (mPos.x < 192)
		mVelocityX = mSpeed;

	if (mPos.x > 1428)
		mVelocityX = -mSpeed;

	this->move(mVelocityX * delta, 0);
}

void Mob1::Shoot()
{
	if (mTimerShoot > mShootingDelay)
	{
		EnemyBall* b = new EnemyBall(1, 1, mScaleBall, 0, 750);

		b->setPosition(getPosition());
		GameManager::Get()->GetCurrentScene()->addEntity(b);
		mTimerShoot = 0;
	}

	return;
}