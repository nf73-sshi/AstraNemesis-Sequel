#pragma once
#include "Entity.h"
#include "Ball.h"
#include "Character.h"

class Player : public Character, public Collide
{
	bool mIsInvincible;
	float mTimerInvincible;
	float mTimerInactive;

public:
	Player();

	void Move(float delta);

	void Shoot() override;

	void ScreenCollision();

	void InvincibleAnim(float delta);

	void ResetInvincible(float delta);


	void Update(float delta) override;


	// Hérité via Collide
	Hitbox GetHitbox() override;

	void OnCollide(Entity* e) override;

};

