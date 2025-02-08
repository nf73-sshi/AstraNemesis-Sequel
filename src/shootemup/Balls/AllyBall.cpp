#include "AllyBall.h"
#include "../Bosses/Boss1.h"
#include "../PlayerMobs/Mob1.h"

AllyBall::AllyBall(int damage, float speed, float scale, float xFactor, float yFactor) : Ball(damage, speed, scale, xFactor, yFactor)  
{
	CreateSprite("../../../res/assets/Images/bulletsTile.png", 252.5, 325, 18, 18);
}

int AllyBall::GetDamage()
{
	return mDamage;
}

void AllyBall::OnCollide(Entity* e)
{
	if (typeid(*e) == typeid(Boss1))
	{
		if(e->IsDead() == false)
			mDestroy = true;
	}
	
	if (typeid(*e) == typeid(Mob1))
	{
		if (e->IsDead() == false) 
			mDestroy = true;
	}

	return;
}
