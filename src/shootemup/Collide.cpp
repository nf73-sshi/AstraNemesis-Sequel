#include "Collide.h"


bool Collide::CheckCollision(Collide* other)
{
	Hitbox hitbox = GetHitbox();
	Hitbox hitboxOther = other->GetHitbox(); 

	float d = sqrt(pow(hitboxOther.position.x - hitbox.position.x, 2) + pow(hitboxOther.position.y - hitbox.position.y, 2));

	if (d <= hitbox.radius + hitboxOther.radius)
	{
		return true;
	}

	return false;
}
