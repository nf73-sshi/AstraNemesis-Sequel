#include "Boss1.h"
#include "EnemyBall.h"
#include "AllyBall.h"
#include "Player.h"
#include "GameManager.h"
#include <iostream>
#include <typeinfo>

Boss1::Boss1() : Character("Boss 1", 50, 1, 500, 0.25)
{
	srand(time(0));
	mRandomizer = 1;
	mTimerInactive = 0;
	mTimerShoot = 0;
	mTimerPattern1 = 0;
	mTimerPattern2 = 0;
	mTimerPattern3 = 0;
	mScaleBall = 1;
	mVelocityX = mSpeed;
	mVelocityY =mSpeed * 2.5;

	CreateSprite("../../../res/assets/Images/Boss1.png", 0, 0, 533, 255);
}

void Boss1::Update(float delta)  
{
	if (mTimerInactive < 2)
	{
		mTimerInactive += delta;
		return;
	}

	mPos = GetPosition();
	mTimerShoot += delta;
	mTimerPattern1 += delta; 

	if (mTimerPattern1 <= 2)
	{
		Pattern1(delta);
		Shoot();
	}

	if (mTimerPattern1 > 2)
	{
		if(mRandomizer == 1)
			Pattern2(delta);
		if (mRandomizer == 2)
			Pattern3(delta);
	}

	if (IsDead() == true)
	{
		mDestroy = true;
	}
}

void Boss1::Randomize()
{
	mRandomizer = 1 + rand() % 2;
}

void Boss1::Shoot()
{
	if (mTimerShoot > mShootingDelay)
	{
		EnemyBall* b = new EnemyBall(1, 1, mScaleBall, 0, 1000);

		b->setOrigin(9.f, 9.f);
		b->setPosition(getPosition());
		GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
		mTimerShoot = 0;
	}

	return;
}

void Boss1::Pattern1(float delta)
{
	if (mPos.x < 533)
		mVelocityX = mSpeed;

	if (mPos.x > 1387)
		mVelocityX = -mSpeed;

	this->move(mVelocityX * delta, 0);
}

void Boss1::Pattern2(float delta)
{
	mTimerPattern2 += delta;

	if (mTimerPattern2 >= 0.5)
	{
		for (int i = -5; i < 5; i++)
		{
			EnemyBall* b = new EnemyBall(1, 1, mScaleBall * 2, i * 100.f, 500);

			b->setOrigin(9.f, 9.f);
			b->setPosition(getPosition());
			GameManager::GetInstance()->GetCurrentScene()->addEntity(b);

		}

		mTimerPattern1 = 0;
		mTimerPattern2 = 0;
		Randomize();
	}


}

void Boss1::Pattern3(float delta)
{
	mTimerPattern3 += delta;

	if (mTimerPattern3 >= 1)
	{
		for (int i = 0; i < 1; i++)
		{
			EnemyBall* b = new EnemyBall(1, 1, mScaleBall * 10, 0, 1000);

			b->setOrigin(9.f, 9.f);
			b->setPosition(getPosition());
			GameManager::GetInstance()->GetCurrentScene()->addEntity(b);

		}

		mTimerPattern1 = 0;
		mTimerPattern3 = 0;
		Randomize();
	}
}

Hitbox Boss1::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = 127.5f;
	return h;
}

void Boss1::OnCollide(Entity* e)
{

	if (typeid(*e) == typeid(AllyBall))
	{
		AddRemoveHP(-1);
		std::cout << mHP << " Restants pour le boss" << std::endl;
	}

	if (IsDead())
	{
		mDestroy = true;
	}

}

