#include "Ball.h"
#include <iostream>

Ball::Ball(int damage, float speed, float direction)
{
	mDamage = damage;
	mSpeed = speed;
	mDirection = direction;
	mCurrentTime = 0;
	CreateSprite("../../../res/assets/Images/bulletsTile.png", 167, 297, 17, 17);
}

int Ball::GetDamage()
{
	return mDamage;
}

float Ball::GetSpeed()
{
	return mSpeed;
}

float Ball::GetDirection()
{
	return mDirection;
}

void Ball::SetDamage(int damage)
{
	mDamage = damage;
}

void Ball::SetSpeed(float speed)
{
	mSpeed = speed;
}

void Ball::SetDirection(float direction)
{
	mDirection = direction;
}

void Ball::SpawnBullet() {}
void Ball::DestroyBullet() {}

void Ball::Update(float delta)
{
	sf::Vector2f pos = getPosition();

	this->move(0, delta * -mSpeed);
	mCurrentTime += delta;
}

Hitbox Ball::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = 9;
	return h; 
}

void Ball::OnCollide(Entity*)
{
	std::cout << "BOOM" << std::endl;
}
