#include "Ball.h"
#include <iostream>

Ball::Ball(int damage, float speed, float scale, float xFactor, float yFactor)
{
	mDrawPriority = 1;
	mCurrentScene = GameManager::Get()->GetCurrentScene();
	mDamage = damage;
	mSpeed = speed;
	mScale = scale;
	this->setScale(mScale, mScale); 
	mXFactor = xFactor;
	mYFactor = yFactor;
	mCurrentTime = 0;
	mCurrentTime = 0;
}

int Ball::GetDamage()
{
	return mDamage;
}

float Ball::GetSpeed()
{
	return mSpeed;
}

float Ball::GetXFactor()
{
	return mXFactor;
}

float Ball::GetYFactor()
{
	return mYFactor;
}

void Ball::SetSize(float size) 
{
	mScale = size;
}

void Ball::SetDamage(int damage)
{
	mDamage = damage;
}

void Ball::SetSpeed(float speed)
{
	mSpeed = speed;
}

void Ball::SetDirection(float xFactor, float yFactor)
{
	mXFactor = xFactor;
	mYFactor = yFactor;
}

void Ball::Update(float delta)
{
	sf::Vector2f pos = getPosition();

	this->move(mXFactor * delta * mSpeed, mYFactor * delta * mSpeed); 
	mCurrentTime += delta; 

	if (getPosition().x < 0.f || getPosition().x > 1620.f || getPosition().y < 0.f || getPosition().y > 1080.f)
		mDestroy = true;

}

Hitbox Ball::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = 8.5f * mScale;
	return h; 
}

void Ball::OnCollide(Entity*)
{
	return;
}
