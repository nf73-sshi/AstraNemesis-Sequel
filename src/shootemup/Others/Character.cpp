#include "Character.h"
#include <iostream>

Character::Character(const char* name, int hp, int damage, float speed, float shootingDelay) : Health(hp) 
{
	mName = name;
	mSpeed = speed;
	mDamage = damage;
	mScaleBall = 1;
	mTimerShoot = 0;
	mTimerDelay = 0;
	mTimerInactive = 0;
	mShootingDelay = shootingDelay; 

	mDefaultSpeed = mSpeed;
	mDefaultScaleBall = mScaleBall;
	mDefaultDamage = mDamage;
	mDefaultSDelay = mShootingDelay;

	mEndTimer = 0;
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

void Character::SetSpeed(float newSpeed)
{
	mSpeed = newSpeed;
}

int Character::GetDamage()
{
	return mDamage;
}

float Character::GetShootingDelay()
{
	return mShootingDelay;
}

void Character::SetShootingDelay(float newSDelay)
{
	mShootingDelay = newSDelay;

	if (mShootingDelay <= 0)
	{
		mShootingDelay = 0.001f;
	}
}

void Character::AddRemoveShootingDelay(float value)
{
	mShootingDelay += value;

	if (mShootingDelay <= 0)
	{
		mShootingDelay = 0.001f;
	}
}

float Character::GetDefaultSpeed()
{
	return mDefaultSpeed;
}

float Character::GetDefaultScaleBall()
{
	return mDefaultScaleBall;
}

int Character::GetDefaultDamage()
{
	return mDefaultDamage;
}

float Character::GetDefaultSDelay()
{
	return mDefaultSDelay;
}
