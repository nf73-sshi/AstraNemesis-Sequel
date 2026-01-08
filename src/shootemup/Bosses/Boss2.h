#pragma once
#include "ABoss.h"

class Boss2 : public ABoss
{
public:
	Boss2();
	void Update(float dt) override;
	void Shoot() override;

	std::vector<Hitbox> GetHitboxes() override;

	void PatternGlobal(float dt);
};

