#include "Boss2.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "../PlayerMobs/Player.h"
#include "../PlayerMobs/Mob1.h"
#include "../Important/GameManager.h"
#include <iostream>
#include <typeinfo>
#include "../Important/AssetManager.h"

Boss2::Boss2() : ABoss("Boss2", 2000, 1, 700.f, 0.4f, 2.f, 1.5f)
{
	mVelocityX = mSpeed;
	mVelocityY = mSpeed;

	mHitboxSize = 63.f;

	CreateSprite("Boss2", 0, 0, 236, 236);
}

void Boss2::Update(float dt)
{
	ABoss::Update(dt);

	auto linkedMusic = AssetManager::Get()->GetMusic("Dynamic Music1");

	if (mTimerInactive < 2)
	{
		mTimerInactive += dt;
		return;
	}

	mTimerDelay += dt;
	mTimerShoot += dt;

	PatternGlobal(dt);
}

void Boss2::Shoot()
{
	static int currentCount = 0;
	const int shootBeforeBig = 8;

	if (mTimerShoot > mShootingDelay)
	{
		currentCount++;

		for (int i = -1; i < 2; i += 2)
		{
			EnemyBall* b = new EnemyBall(1, 800.f, mScaleBall, 0, 1);

			sf::Vector2f pos = getPosition();
			pos.x += i * 95.f * GetMaxScale();

			b->setPosition(pos);

			GameManager::Get()->GetCurrentScene()->addEntity(b);
		}

		if (currentCount >= shootBeforeBig)
		{
			EnemyBall* b = new EnemyBall(1, 1000.f, mScaleBall * 4.f, 0, 1);

			sf::Vector2f pos = getPosition();
			b->setPosition(pos);

			if (Player* pPlayer = GameManager::Get()->GetCurrentScene()->GetFirst<Player>())
			{
				sf::Vector2f vect = pPlayer->getPosition() - b->getPosition();
				b->SetDirection(vect.x, vect.y);
			}

			GameManager::Get()->GetCurrentScene()->addEntity(b);

			currentCount = 0;
		}

		mTimerShoot = 0;
	}

	return;
}

std::vector<Hitbox> Boss2::GetHitboxes()
{
	std::vector<Hitbox> hitboxes;

	sf::Vector2f pos = getPosition();

	float realSize = mHitboxSize * GetMaxScale();

	sf::Vector2f offset = { 80.f * GetMaxScale(), 50.f * GetMaxScale(false) };

	Hitbox main(pos, realSize, {0.f, -25.f * GetMaxScale(false)});
	Hitbox leftWing(pos, realSize * 0.6f, { -offset.x, offset.y });
	Hitbox rightWing(pos, realSize * 0.6f, { offset.x, offset.y });

	hitboxes = { main, leftWing, rightWing };

	return hitboxes;
}

void Boss2::PatternGlobal(float dt)
{
	float realSize = mHitboxSize * GetMaxScale();

	if (getPosition().x < realSize)
		mVelocityX = mSpeed;

	if (getPosition().x > WINDOW_WIDTH - 300.f - realSize)
		mVelocityX = -mSpeed;

	this->move(mVelocityX * dt, 0);

	Shoot();
}
