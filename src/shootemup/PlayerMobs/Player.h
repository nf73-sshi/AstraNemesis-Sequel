#pragma once
#include "../Others/Entity.h"
#include "../Balls/Ball.h"
#include "../Others/Character.h"
#include "../HealthMana/Mana.h"
#include "../HealthMana/ManaBar.h"
#include "../HealthMana/HealthBar.h"
#include "../Skills/Skill.h"

#include "../Important/res.h"

class Mana; 

class Skill; 

class Player : public Character, public Mana, public Collide 
{
	int mCurrentMana;
	int mMaxMana;
protected:
	bool mIsInvincible;
	float mTimerInvincible;
	float mTimerInactive;

	HealthBar* mHB;
	ManaBar* mManaBar;

	std::vector<Skill*> skillArray;

public:
	Player();

	void Move(float delta);

	void SetLifeBar(HealthBar* pHB);

	void SetManaBar(ManaBar* pManaBar); 

	void Shoot() override;

	void ScreenCollision();

	void InvincibleAnim(float delta);

	void ResetInvincible(float delta);


	void Update(float delta) override;

	bool GetIsInvincible();
	void SetInvincible(bool value); 

	void SkillManager(float delta);


	Hitbox GetHitbox() override;

	void OnCollide(Entity* e) override;

};

