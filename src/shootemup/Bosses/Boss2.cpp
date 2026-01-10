#include "Boss2.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "../PlayerMobs/Player.h"
#include "../PlayerMobs/Mob1.h"
#include "../Important/GameManager.h"
#include <iostream>
#include <typeinfo>
#include "../Important/AssetManager.h"

#include "../Actions/ActionsBoss2.h"

Boss2::Boss2() : ABoss("Boss2", 2000, 1, 500.f, 0.4f, 2.f, 1.5f), m_SM(this)
{
	mVelocityX = mSpeed;
	mVelocityY = mSpeed * 1.5f;

	mHitboxSize = 63.f;

	CreateSprite("Boss2", 0, 0, 236, 236);

	m_SM.AddAction(PATTERNGLOBAL, new ActionPatternGlobal(3.f));
	m_SM.AddAction(PATTERN1, new ActionPattern1(3.f));
	m_SM.AddAction(PATTERN2, new ActionPattern2(2.f));

	m_SM.ChangeState(PATTERNGLOBAL);
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

	m_SM.Update();
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
			sf::Vector2f pos = getPosition();
			pos.x += i * 95.f * GetMaxScale();

			SpawnBall(0, 800.f, 0.8f, pos, { 0, 1 });
		}

		if (currentCount >= shootBeforeBig)
		{
			EnemyBall* b = SpawnBall(0, 1000.f, 1, getPosition(), { 0, 0 });

			if (Player* pPlayer = GameManager::Get()->GetCurrentScene()->GetFirst<Player>())
			{
				sf::Vector2f vect = pPlayer->getPosition() - b->getPosition();
				b->SetDirection(vect.x, vect.y);
			}

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

bool Boss2::DashForward(float dt, float maxPos)
{
	if (getPosition().y >= maxPos)
	{
		SetPosition(getPosition().x, maxPos);
		return false;
	}

	this->move(0, mVelocityY * dt);

	return true;
}

bool Boss2::DashBackward(float dt)
{
	float defaultPosY = GetDefaultPosition().y;

	if (getPosition().y <= defaultPosY)
	{
		SetPosition(getPosition().x, defaultPosY);
		return false;
	}

	this->move(0, -mVelocityY * dt);

	return true;
}

void Boss2::Slide(float dt)
{
	float realSize = mHitboxSize * GetMaxScale();

	if (getPosition().x < realSize)
		mVelocityX = mSpeed;

	if (getPosition().x > WINDOW_WIDTH - 300.f - realSize)
		mVelocityX = -mSpeed;

	this->move(mVelocityX * dt, 0);
}
