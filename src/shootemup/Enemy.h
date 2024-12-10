#pragma once
#include "Entity.h"

class Enemy : public Entity
{
	const char* mName;
	float mSpeed;
	int mDamage;
	float mShootingDelay;

public:
	Enemy(const char* name, float speed, int damage, float shootingDelay);

	void Update(float delta) override;

};

