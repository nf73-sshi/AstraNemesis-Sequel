#pragma once
#include "Entity.h"
#include "Collide.h"

class Ball : public Entity, public Collide
{
	int mDamage;
	float mSpeed;
	float mDirection;
	float mCurrentTime;
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

	// Hérité via Collide
	Hitbox GetHitbox() override;
	void OnCollide(Entity*) override;
};

