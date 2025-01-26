#pragma once
#include "Entity.h"
#include "Ball.h"
#include "Character.h"
#include "HealthBar.h"
#include "Skill.h"

class Skill; 

class Player : public Character, public Collide
{
	int mCurrentMana;
	int mMaxMana;
protected:
	bool mIsInvincible;
	float mTimerInvincible;
	float mTimerInactive;

	HealthBar* mHB;

	Skill* s1;

public:
	Player();

	void Move(float delta);

	void SetLifeBar(HealthBar* pHB);

	void Shoot() override;

	void ScreenCollision();

	void InvincibleAnim(float delta);

	void ResetInvincible(float delta);


	void Update(float delta) override;


	// Hérité via Collide
	Hitbox GetHitbox() override;

	void OnCollide(Entity* e) override;

};

