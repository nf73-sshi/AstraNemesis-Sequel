#pragma once
#include "Entity.h"
#include "Ball.h"
#include "Character.h"
#include "HealthBar.h"
#include "Skill.h"

class Player : public Character, public Collide
{

protected:
	bool mIsInvincible;
	float mTimerInvincible;
	float mTimerInactive;
	//Skill mReloadBoost;
	float mReloadSkill2;
	float mDurSKill2;
	HealthBar* mHB;
	bool mSkill2Used;

public:
	Player();

	void Move(float delta);

	void SetLifeBar(HealthBar* pHB);

	void Shoot() override;

	void TriggerSkill2();

	void UseSkill1(float delta); // Shield
	void UseSkill2(float delta); // Boost de mReload
	void UseSkill3(float delta); // Mega tirs

	void ScreenCollision();

	void InvincibleAnim(float delta);

	void ResetInvincible(float delta);


	void Update(float delta) override;


	// Hérité via Collide
	Hitbox GetHitbox() override;

	void OnCollide(Entity* e) override;

};

