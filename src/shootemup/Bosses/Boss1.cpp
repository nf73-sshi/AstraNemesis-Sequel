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
#include "../Important/AssetManager.h"

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

	auto linkedMusic = AssetManager::Get()->GetMusic("Dynamic Music2");

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

		if (linkedMusic->getPitch() < 1.1)
		{
			AssetManager::Get()->GetSound("Explosion1")->play(); 
			linkedMusic->setPitch(1.1);
		}

	}
	else if (mHP <= mHPMax * 0.33)
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

		if (linkedMusic->getPitch() < 1.2)
		{
			AssetManager::Get()->GetSound("Explosion1")->play();
			linkedMusic->setPitch(1.2);
		}

	}
	else
	{
		if (linkedMusic->getPitch() != 1.f)
			linkedMusic->setPitch(1.f);
	}

	if (Health::IsDead())
	{
		AssetManager::Get()->GetSound("Explosion1")->play(); 
		mDestroy = true;
		return;
	}

	mTimerDelay += delta;
	mTimerShoot += delta;
	mTimerPattern1 += delta; 

	if (mTimerPattern1 <= mAtkSpeed)
	{
		Pattern1(delta);
		Shoot();
	}

	const int P1 = 40; // 60
	const int P2 = 70;  // 90

	if (mTimerPattern1 > mAtkSpeed)
	{
		if(mRandomizer < P1)
			Pattern2(delta);
		if (mRandomizer >= P1 && mRandomizer < P2)
			Pattern3(delta); 
		if (mRandomizer >= P2)
			Pattern4(delta);
	}
}

void Boss1::Shoot()
{
	if (mTimerShoot > mShootingDelay)
	{
		EnemyBall* b = new EnemyBall(1, 1, mScaleBall, 0, 800);
    
		b->setPosition(getPosition());
		GameManager::Get()->GetCurrentScene()->addEntity(b);
		mTimerShoot = 0;
	}

	return;
}

void Boss1::Pattern1(float delta)
{
	if (getPosition().x < 100)
		mVelocityX = mSpeed + mSpeedBoost;

	if (getPosition().x > 1550)
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

			b->setPosition(getPosition());
			GameManager::Get()->GetCurrentScene()->addEntity(b);

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

			b->setPosition(getPosition());
			GameManager::Get()->GetCurrentScene()->addEntity(b);

		}

		mTimerPattern1 = 0;
		mTimerPattern3 = 0;
		mTimerShoot = 0;
		Randomize();
	}
}

void Boss1::Pattern4(float delta)
{
	if (GameManager::Get()->GetCurrentScene()->GetAll<Mob1>().size() >= 4)
	{
		mRandomizer = rand() % 90;
		return;
	}

	mTimerPattern4 += delta;

	if (mTimerPattern4 >= 0.5)
	{
		for (int i = 0; i < 3; i++)
		{
			Mob* b = new Mob1();
			b->setScale(3, 3);
			b->setPosition(WINDOW_WIDTH * 0.12 + i* 500 , -192);
			GameManager::Get()->GetCurrentScene()->addEntity(b);
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

			b->setPosition(getPosition());
			GameManager::Get()->GetCurrentScene()->addEntity(b);
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

