#pragma once
#include "Entity.h"
#include "Ball.h"
#include "Character.h"

class Player : public Character
{
	const char* mName;
	int mDamage;
	float mSpeed;
	float mShootingDelay;

public:
	Player(const char* name, int damage, float speed, float shootingDelay);

	void Shoot();

	void Update(float delta) override;


};

