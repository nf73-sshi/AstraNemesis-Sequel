#include "Character.h"
#include <iostream>

Character::Character(const char* name, int hp, int damage, float speed, float shootingDelay) : Health(hp)
{
	mName = name;
	mSpeed = speed;
	mDamage = damage;
	mScaleBall = 1;
	mShootingDelay = shootingDelay;
	mTimerShoot = 0;
}

sf::Vector2f Character::GetPosition()
{
	mPos = this->getPosition();

	return mPos;
}

void Character::Update(float delta)
{
	return;
}

void Character::Shoot()
{
	std::cout << "Bug de tir" << std::endl;
	return;
}

float Character::GetSpeed()
{
	return mSpeed;
}

int Character::GetDamage()
{
	return mDamage;
}

float Character::GetShootingDelay()
{
	return mShootingDelay;
}
