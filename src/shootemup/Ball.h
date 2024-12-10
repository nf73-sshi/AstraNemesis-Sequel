#pragma once
#include "Entity.h"

class Ball : public Entity
{
	int mDamage;
	float mSpeed;
	float mDirection;

public:
	Ball(int damage, float speed, float direction);

	int GetDamage();
	float GetSpeed();
	float GetDirection();
	void SetDamage(int damage);
	void SetSpeed(float speed);
	void SetDirection(float direction);
	void SpawnBullet();
	void DestroyBullet();

	void Update(float delta) override;
};

