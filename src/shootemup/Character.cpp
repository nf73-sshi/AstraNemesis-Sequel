#include "Character.h"

Character::Character(const char* name, int damage, float speed, float shootingDelay)
{
	mName = name;
	mSpeed = speed;
	mDamage = damage;
	mShootingDelay = shootingDelay;
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
