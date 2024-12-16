#include "EnemyBall.h"

EnemyBall::EnemyBall(int damage, float speed, float scale, float xFactor, float yFactor) : Ball(damage, speed, scale, xFactor, yFactor)
{
	CreateSprite("../../../res/assets/Images/bulletsTile.png", 295.5, 325, 18, 18);
}
