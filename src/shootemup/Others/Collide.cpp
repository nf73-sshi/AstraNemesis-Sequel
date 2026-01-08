#include "Collide.h"
#include "../Important/GameManager.h"
#include "../Important/Debug.h"

bool Collide::CheckCollision(Collide* other)
{
	if (!other)
		return false;

	auto hitboxes = GetHitboxes();
	auto hitboxesOther = other->GetHitboxes();

	for (const Hitbox& h : hitboxes)
	{
		for (const Hitbox& hOther : hitboxesOther)
		{
			float dx = hOther.position.x - h.position.x;
			float dy = hOther.position.y - h.position.y;

			float sqrDist = dx * dx + dy * dy;

			float sumRadius = h.radius + hOther.radius;

			if (sqrDist <= sumRadius * sumRadius)
			{
				return true;
			}
		}
	}

	return false;
}

void Hitbox::Draw()
{
	if(GameManager::Get()->GetIsDebugMod())
		Debug::DrawFilledCircle(this->position, this->radius, sf::Color(255, 0, 0, 150));
}
