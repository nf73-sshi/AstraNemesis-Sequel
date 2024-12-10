#include "Enemy.h"

Enemy::Enemy(const char* name, float speed, int damage, float shootingDelay)
{
	mName = name;
	mSpeed = speed;
	mDamage = damage;
	mShootingDelay = shootingDelay;
}

void Enemy::Update(float delta)
{
	return;
}
