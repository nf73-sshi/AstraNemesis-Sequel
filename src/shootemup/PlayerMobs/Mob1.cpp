#include "Mob1.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "Player.h"
#include "../Important/GameManager.h"

Mob1::Mob1() : Mob("Mob1", 30, 1, 300, 0.5)
{
	mDrawPriority = 6;
	mTimerMove = 0;
	CreateSprite("MobsTile", 20, 14, 43, 33);
	mRdm = 0;

	manaReward = 3;
}


void Mob1::Update(float delta)
{
	Mob::Update(delta);

	if (mTimerInactive < 1.5)
	{
		this->move(0, 310 * delta);
		mTimerInactive += delta;
		return;
	}

	Shoot();
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

	if (getPosition().x < 192)
		mVelocityX = mSpeed;

	if (getPosition().x > 1428)
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

Hitbox Mob1::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = 65;
	return h;
}