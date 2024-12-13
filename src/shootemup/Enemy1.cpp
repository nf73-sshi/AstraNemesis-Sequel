#include "Enemy1.h"
#include <iostream>

Enemy1::Enemy1(const char* name, int hp, int damage, float speed, float shootingDelay) : Character(name, hp, damage, speed, shootingDelay)
{
	mTimer = 0;
	mTimer2 = 0;
	mSpeed = speed;
	mVelocityX = mSpeed;
	mVelocityY =mSpeed * 3;

	CreateSprite("../../../res/assets/Images/bosscaca.png", 0, 0, 533, 255);
}

void Enemy1::Update(float delta)  
{
	mPos = GetPosition();
	mTimer += delta; 

	if (mTimer <= 2)
		Pattern1(delta);

	if(mTimer > 2)
		Pattern2(delta);

}

void Enemy1::Pattern1(float delta)
{
	if (mPos.x < 533)
		mVelocityX = mSpeed;

	if (mPos.x > 1387)
		mVelocityX = -mSpeed;

	this->move(mVelocityX * delta, 0);
}

void Enemy1::Pattern2(float delta)
{
	mTimer2 += delta;

	if(mTimer2 < 0.6)
		this->move(0, mVelocityY * delta);
	if (mTimer2 >= 0.6)
		this->move(0, -mVelocityY * delta);

	if (mPos.y < 127.5)
		this->setPosition(mPos.x, 127.5);

	if (mTimer2 > 1.2)
	{
		mTimer = 0;
		mTimer2 = 0;
	}

}

Hitbox Enemy1::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = 127.5f;
	return h;
}

void Enemy1::OnCollide(Entity*)
{
	mHP--;
	std::cout << mHP << std::endl;
}

