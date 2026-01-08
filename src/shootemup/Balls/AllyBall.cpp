#include "AllyBall.h"
#include "../Bosses/ABoss.h"
#include "../PlayerMobs/Mob1.h"

AllyBall::AllyBall(int damage, float speed, float scale, float xFactor, float yFactor) : Ball(damage, speed, scale, xFactor, yFactor)  
{
	CreateSprite("BulletsTile", 252.5, 325, 18, 18); 
}

int AllyBall::GetDamage()
{
	return mDamage;
}

void AllyBall::OnCollide(Entity* e)
{
	if (ABoss* boss = dynamic_cast<ABoss*>(e))
		mDestroy = true;

	if (Mob* target = dynamic_cast<Mob*>(e))
		mDestroy = true;

	return;
}
