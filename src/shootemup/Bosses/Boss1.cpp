#include "Boss1.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "../PlayerMobs/Player.h"
#include "../PlayerMobs/Mob1.h"
#include "../Important/GameManager.h"
#include <iostream>
#include <typeinfo>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

Boss1::Boss1() : ABoss("Boss1", 2000, 1, 400, 0.35, 2.f, 1.5f)
{
	mHitboxSize = 127.5f;

	mTimerPattern1 = 0;
	mTimerPattern2 = 0;
	mTimerPattern3 = 0;
	mTimerPattern4 = 0; 
	mTimerPattern5 = 0;

	mSpeedBoost = 0;

	mVelocityX = mSpeed;
	mVelocityY = mSpeed * 2.5;
	CreateSprite("Boss1", 0, 0, 533, 255);
}

void Boss1::Update(float delta)  
{
	ABoss::Update(delta);

	if (mTimerInactive < 2)
	{
		mTimerInactive += delta;
		return;
	}

	if (mHP <= mHPMax * 0.66 && mHP > mHPMax * 0.33)
	{
		this->sprite.setColor(sf::Color(255, 120, 120, 255));
		mShootingDelay = 0.25;
		mAtkSpeed = 1.5f;
		mSpeedBoost = 100;

		if (mRandomizer <= 30)
		{
			Pattern5(delta);
			Randomize();
		}
	}

	if (mHP <= mHPMax * 0.33)
	{
		this->sprite.setColor(sf::Color(255, 50, 50, 255));
		mShootingDelay = 0.2;
		mAtkSpeed = 1.f;
		mSpeedBoost = 250;

		if (mRandomizer <= 50)
		{
			Pattern5(delta);
			Randomize();
		}
	}

	if (Health::IsDead())
	{
		mDestroy = true;
		return;
	}

	mPos = GetPosition();
	mTimerDelay += delta;
	mTimerShoot += delta;
	mTimerPattern1 += delta; 

	if (mTimerPattern1 <= mAtkSpeed)
	{
		Pattern1(delta);
		Shoot();
	}

	if (mTimerPattern1 > mAtkSpeed)
	{
		if(mRandomizer < 60)
			Pattern2(delta);
		if (mRandomizer >= 60 && mRandomizer < 90)
			Pattern3(delta); 
		if (mRandomizer >= 90)
			Pattern4(delta);
	}
}

void Boss1::Shoot()
{
	if (mTimerShoot > mShootingDelay)
	{
		EnemyBall* b = new EnemyBall(1, 1, mScaleBall, 0, 800);
    
		b->setOrigin(9.f, 9.f);
		b->setPosition(getPosition());
		GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
		mTimerShoot = 0;
	}

	return;
}

void Boss1::Pattern1(float delta)
{
	if (mPos.x < 100)
		mVelocityX = mSpeed + mSpeedBoost;

	if (mPos.x > 1550)
		mVelocityX = -mSpeed - mSpeedBoost;

	this->move(mVelocityX * delta, 0);
}

void Boss1::Pattern2(float delta)
{
	mTimerPattern2 += delta;

	if (mTimerPattern2 >= 0.5)
	{
		for (int i = -5; i < 6; i++)
		{
			EnemyBall* b = new EnemyBall(1, 1, 2.5, i * 125.f, 600);

			b->setOrigin(9.f, 9.f);
			b->setPosition(getPosition());
			GameManager::GetInstance()->GetCurrentScene()->addEntity(b);

		}

		mTimerPattern1 = 0;
		mTimerPattern2 = 0;
		mTimerShoot = 0;
		Randomize();
	}


}

void Boss1::Pattern3(float delta)
{
	mTimerPattern3 += delta;

	if (mTimerPattern3 >= 0.75)
	{
		for (int i = 0; i < 1; i++)
		{
			EnemyBall* b = new EnemyBall(1, 1, 18, 0, 250);

			b->setOrigin(9.f, 9.f);
			b->setPosition(getPosition());
			GameManager::GetInstance()->GetCurrentScene()->addEntity(b);

		}

		mTimerPattern1 = 0;
		mTimerPattern3 = 0;
		mTimerShoot = 0;
		Randomize();
	}
}

void Boss1::Pattern4(float delta)
{
	mTimerPattern4 += delta;

	if (mTimerPattern4 >= 0.5)
	{
		for (int i = 0; i < 3; i++)
		{
			Mob1* b = new Mob1();
			b->setOrigin(32, 32);
			b->setScale(3, 3);
			b->setPosition(WINDOW_WIDTH * 0.12 + i* 500 , -192);
			GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
		}

		mTimerPattern1 = 0;
		mTimerPattern4 = 0;
		mTimerShoot = 0;
		mRandomizer = rand() % 90;
	}

}

void Boss1::Pattern5(float delta)
{
	mTimerPattern5 += delta;

	if (mTimerPattern5 > 0.1)
	{
		for (int i = -1; i < 2; i++)
		{
			EnemyBall* b = new EnemyBall(1, 1, 4, i * 300, 750);

			b->setOrigin(9.f, 9.f);
			b->setPosition(getPosition());
			GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
		}

		mTimerPattern1 = 0;
		mTimerPattern5 = 0;
		mTimerShoot = 0;
	}
	
}

Hitbox Boss1::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = mHitboxSize;
	return h;
}

void Boss1::OnCollide(Entity* e)
{
	ABoss::OnCollide(e);
}

