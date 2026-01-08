#include "Boss1.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "../PlayerMobs/Player.h"
#include "../PlayerMobs/Mob1.h"
#include "../Important/GameManager.h"
#include <iostream>
#include <typeinfo>
#include "../Important/AssetManager.h"

Boss1::Boss1() : ABoss("Boss1", 4000, 1, 400, 0.5f, 2.f, 1.5f)
{
	mHitboxSize = 64.f;

	mTimerPattern1 = 0;
	mTimerPattern2 = 0;
	mTimerPattern3 = 0;
	mTimerPattern4 = 0; 
	mTimerPattern5 = 0;

	mSpeedBoost = 0;

	mVelocityX = mSpeed;
	mVelocityY = mSpeed * 2.5f;
	CreateSprite("Boss1", 0, 0, 533, 255);
}

void Boss1::Update(float dt)  
{
	ABoss::Update(dt);

	auto linkedMusic = AssetManager::Get()->GetMusic("Dynamic Music2");

	if (mTimerInactive < 2)
	{
		mTimerInactive += dt;
		return;
	}

	if (mHP <= mHPMax * 0.66 && mHP > mHPMax * 0.33)
	{
		this->sprite.setColor(sf::Color(255, 120, 120, 255));
		mShootingDelay = 0.3f;
		mAtkSpeed = 1.5f;
		mSpeedBoost = 100;

		if (mRandomizer <= 30)
		{
			PatternTripleBall(dt);
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
		mShootingDelay = 0.4f;
		mAtkSpeed = 1.f;
		mSpeedBoost = 250;

		if (mRandomizer <= 50)
		{
			PatternTripleBall(dt);
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

	mTimerDelay += dt;
	mTimerShoot += dt;
	mTimerPattern1 += dt; 

	if (mTimerPattern1 <= mAtkSpeed)
		PatternGlobal(dt);

	const int P1 = 60; // 60
	const int P2 = 90;  // 90

	if (mTimerPattern1 > mAtkSpeed)
	{
		if(mRandomizer < P1)
			PatternSweepBall(dt);
		if (mRandomizer >= P1 && mRandomizer < P2)
			PatternBigBall(dt); 
		if (mRandomizer >= P2)
			PatternSpawnMobs(dt);
	}
}

void Boss1::Shoot()
{
	if (mTimerShoot > mShootingDelay)
	{
		EnemyBall* b = new EnemyBall(1, 800.f, mScaleBall, 0, 0);
    
		b->setPosition(getPosition());

		if (Player* pPlayer = GameManager::Get()->GetCurrentScene()->GetFirst<Player>())
		{
			sf::Vector2f vect = pPlayer->getPosition() - b->getPosition();
			b->SetDirection(vect.x, vect.y);
		}

		GameManager::Get()->GetCurrentScene()->addEntity(b);
		mTimerShoot = 0;
	}

	return;
}

void Boss1::PatternGlobal(float delta)
{
	float realSize = mHitboxSize * GetMaxScale();

	if (getPosition().x < realSize)
		mVelocityX = mSpeed + mSpeedBoost;

	if (getPosition().x > WINDOW_WIDTH - 300.f - realSize)
		mVelocityX = -mSpeed - mSpeedBoost;

	this->move(mVelocityX * delta, 0);

	Shoot();
}

void Boss1::PatternSweepBall(float delta)
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

void Boss1::PatternBigBall(float delta)
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

void Boss1::PatternSpawnMobs(float delta)
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

void Boss1::PatternTripleBall(float delta)
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

std::vector<Hitbox> Boss1::GetHitboxes()
{
	std::vector<Hitbox> hitboxes;

	sf::Vector2f pos = getPosition();

	float realSize = mHitboxSize * GetMaxScale();

	Hitbox main(pos, realSize);

	float offsetX = 200.f * GetMaxScale();
	float offsetY = -50.f * GetMaxScale(false);

	Hitbox leftWing(pos, realSize * 0.7f, {-offsetX, offsetY});
	Hitbox rightWing(pos, realSize * 0.7f, {offsetX, offsetY});

	Hitbox leftShoulder(pos, realSize * 0.9f, { -offsetX * 0.5f, offsetY * 0.5f});
	Hitbox rightShoulder(pos, realSize * 0.9f, { offsetX * 0.5f, offsetY * 0.5f });

	hitboxes = { main, leftWing, rightWing, leftShoulder, rightShoulder };

	return hitboxes;
}

void Boss1::OnCollide(Entity* e)
{
	ABoss::OnCollide(e);
}

