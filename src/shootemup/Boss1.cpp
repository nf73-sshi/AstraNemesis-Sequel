#include "Boss1.h"
#include "EnemyBall.h"
#include "AllyBall.h"
#include "Player.h"
#include <iostream>
#include <typeinfo>

Boss1::Boss1(const char* name, int hp, int damage, float speed, float shootingDelay) : Character(name, hp, damage, speed, shootingDelay)
{
	mTimerShoot = 0;
	mTimerPattern1 = 0;
	mTimerPattern2 = 0;
	mSpeed = speed;
	mVelocityX = mSpeed;
	mVelocityY =mSpeed * 2.5;

	CreateSprite("../../../res/assets/Images/bosscaca.png", 0, 0, 533, 255);
}

void Boss1::Update(float delta)  
{
	mPos = GetPosition();
	mTimerShoot += delta;
	mTimerPattern1 += delta; 

	if (mTimerPattern1 <= 2)
	{
		Pattern1(delta);
		Shoot();
	}

	if(mTimerPattern1 > 2)
		Pattern2(delta);

}

void Boss1::Shoot()
{
	if (mTimerShoot > mShootingDelay) {
		EnemyBall* b = new EnemyBall(1, 1, 2, 0, 1000);

		b->setOrigin(9, 9);
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

	if(mTimerPattern2 < 0.75)
		this->move(0, mVelocityY * delta);
	if (mTimerPattern2 >= 0.75)
		this->move(0, -mVelocityY * delta);

	if (mPos.y < 127.5)
		this->setPosition(mPos.x, 127.5);

	if (mTimerPattern2 > 1.5)
	{
		mTimerPattern1 = 0;
		mTimerPattern2 = 0;
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
		mHP--;
		//std::cout << "Ouch ! :" << mHP << " Restants pour le boss" << std::endl;
	}

}

