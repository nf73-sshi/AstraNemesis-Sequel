#include "Boss1.h"
#include "EnemyBall.h"
#include "AllyBall.h"
#include "Player.h"
#include "GameManager.h"
#include <iostream>
#include <typeinfo>

<<<<<<< Updated upstream
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
=======
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int x = 0;

Boss1::Boss1() : Character("Boss 1", 1000, 1, 400, 0.35)
{
	srand(time(0));
	mRandomizer = 0;
	mTimerPattern1 = 0;
	mTimerPattern2 = 0;
	mTimerPattern3 = 0;
	mTimerPattern4 = 0;
	mScaleBall = 1.5;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
		if (mRandomizer == 2)
			Pattern3(delta);
=======
		if (mRandomizer >= 50 && mRandomizer < 85)
			Pattern3(delta); 
		if (mRandomizer >= 85)
			Pattern4(delta);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
		EnemyBall* b = new EnemyBall(1, 1, mScaleBall, 0, 1000);
=======

		EnemyBall* b = new EnemyBall(1, 1, mScaleBall, 0, 800);
>>>>>>> Stashed changes

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
			EnemyBall* b = new EnemyBall(1, 1, 2.5, i * 100.f, 600);

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

	if (mTimerPattern3 >= 1)
	{
		for (int i = 0; i < 1; i++)
		{
<<<<<<< Updated upstream
			EnemyBall* b = new EnemyBall(1, 1, mScaleBall * 10, 0, 1000);
=======
			EnemyBall* b = new EnemyBall(1, 1, 18, 0, 250);
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
=======
void Boss1::Pattern4(float delta)
{
	mTimerPattern4 += delta;

	if (mTimerPattern4 >= 0.5)
	{
		for (int i = 0; i < 2; i++)
		{
			Mob1* b = new Mob1();
			b->setOrigin(32, 32);
			b->setScale(3, 3);
			b->setPosition(WINDOW_WIDTH * 0.3 + i* 500 , -192);
			GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
		}

		mTimerPattern1 = 0;
		mTimerPattern4 = 0;
		mTimerShoot = 0;
		mRandomizer = rand() % 85;

	}

}

>>>>>>> Stashed changes
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
		GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Menu");
	}

}

