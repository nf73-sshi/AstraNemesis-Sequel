#include "AllyBall.h"
#include "Boss1.h"

AllyBall::AllyBall(int damage, float speed, float scale, float xFactor, float yFactor) : Ball(damage, speed, scale, xFactor, yFactor)  
{
	CreateSprite("../../../res/assets/Images/bulletsTile.png", 252.5, 325, 18, 18);
}

void AllyBall::OnCollide(Entity* e)
{
	if (typeid(*e) == typeid(Boss1))
	{
		mDestroy = true;
	}
		
	return;
}
