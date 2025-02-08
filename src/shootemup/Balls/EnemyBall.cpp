#include "EnemyBall.h"
#include "../PlayerMobs/Player.h" 

EnemyBall::EnemyBall(int damage, float speed, float scale, float xFactor, float yFactor) : Ball(damage, speed, scale, xFactor, yFactor)
{
	CreateSprite("../../../res/assets/Images/bulletsTile.png", 293, 325, 18, 18);
}

void EnemyBall::OnCollide(Entity* e)
{
	if (typeid(*e) == typeid(Player))
		mDestroy = true;

	return;
}
