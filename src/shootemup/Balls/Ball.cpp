#include "Ball.h"
#include <iostream>
#include "../Important/res.h"

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
	auto normal = sqrt(xFactor * xFactor + yFactor * yFactor);

	if (normal == 0)
		return;

	mXFactor = xFactor / normal;
	mYFactor = yFactor / normal;
}

void Ball::Update(float delta)
{
	sf::Vector2f pos = getPosition();
	float radius = GetSprite().getGlobalBounds().width * mScale;

	this->move(mXFactor * delta * mSpeed, mYFactor * delta * mSpeed); 
	mCurrentTime += delta;

	if (pos.x < - radius || pos.x > WINDOW_WIDTH - 300.f + radius || pos.y < 0.f - radius || pos.y > WINDOW_HEIGHT + radius)
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
