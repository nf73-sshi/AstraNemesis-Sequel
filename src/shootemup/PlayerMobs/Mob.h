#pragma once
#include "../Others/Character.h"
#include "../Others/Collide.h"

class HealthBar;

class Mob : public Character, public Collide
{
protected:
	float mVelocityX;
	float mVelocityY;
	int manaReward = 0;
	HealthBar* mHB;
public:
	Mob(const char* name, int hp, int damage, float speed, float shootingDelay);

	virtual void Shoot() = 0;

	virtual void Update(float delta);

	void SetLifeBar();

	virtual Hitbox GetHitbox() = 0;
	void OnCollide(Entity* e) override;
};

