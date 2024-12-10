#include "Enemy1.h"

Enemy1::Enemy1(const char* name, float speed, int damage, float shootingDelay) : Enemy(name, speed, damage, shootingDelay)
{
	CreateSprite("../../../res/assets/Images/bosscaca.png", 0, 0, 533, 255);
}
