#include "Mob1.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "Player.h"
#include "../Important/GameManager.h"
#include <iostream>
#include <typeinfo>
#include "../Important/AssetManager.h"

Mob1::Mob1() : Character("Mob1", 30, 1, 300, 0.5)
{
	mDrawPriority = 6;
	mDestroy = false;
	mVelocityX = mSpeed;
	mVelocityY = mSpeed;
	mTimerMove = 0;
	CreateSprite("MobsTile", 0, 0, 64, 64);
	mRdm = 0;
}


void Mob1::Update(float delta)
{
	if (mTimerInactive < 1.5)
	{
		this->move(0, 310 * delta);
		mTimerInactive += delta;
		return;
	}

	mPos = GetPosition();
	mTimerShoot += delta;
	mTimerMove += delta;
	mTimerDelay += delta;

	Shoot();
	Pattern1(delta);

	if (Health::IsDead() == true)
	{
		AssetManager::Get()->GetSound("Die1")->play(); 
		Player* p = GameManager::GetInstance()->GetCurrentPlayer();

		if (p != nullptr)
		{
			p->AddRemoveMana(3);
		}

		mDestroy = true;
		return;
	}

	return;
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

		b->setOrigin(9.f, 9.f);
		b->setPosition(getPosition());
		GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
		mTimerShoot = 0;
	}

	return;
}

Hitbox Mob1::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = 75;
	return h;
}


void Mob1::OnCollide(Entity* e)
{
	if (mTimerDelay < 0.01)
		return;

	if (typeid(*e) == typeid(AllyBall))
	{
		AddRemoveHP(- e->GetDamage());
		mTimerDelay = 0;
	}

	if (typeid(*e) == typeid(Player))
	{
		Player* currentPlayer = GameManager::GetInstance()->GetCurrentPlayer();

		if (currentPlayer->GetIsInvincible() == true)
			return;


		currentPlayer->SetInvincible(true);
		currentPlayer->AddRemoveHP(-1);
		AssetManager::Get()->GetSound("Hit2")->play();
	}
}
