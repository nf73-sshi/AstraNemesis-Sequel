#include "Collide.h"
#include "../Important/GameManager.h"

bool Collide::CheckCollision(Collide* other)
{
	Hitbox hitbox = GetHitbox();
	Hitbox hitboxOther = other->GetHitbox(); 

	/*sf::CircleShape hitboxSprite;
	hitboxSprite.setPosition(hitbox.position);
	hitboxSprite.setRadius(hitbox.radius);
	hitboxSprite.setFillColor(sf::Color(255, 0, 0, 200));*/

	float d = sqrt(pow(hitboxOther.position.x - hitbox.position.x, 2) + pow(hitboxOther.position.y - hitbox.position.y, 2));

	if (d <= hitbox.radius + hitboxOther.radius)
	{
		return true;
	}

	return false;
}
