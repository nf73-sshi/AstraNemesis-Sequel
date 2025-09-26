#pragma once
#include "../PlayerMobs/Player.h"
#include "../Important/GameManager.h"

class Entity;

class Skill
{

protected:
	int mLvl;
	int mCost;
	float mElapsedTime;
	float mDuration;
	bool mSkillCanBeUsed;
	bool mSkillUsed;

public:
	Skill(int lvl, int cost, float duration);

	int GetLvl();
	float GetCost();
	float GetDuration();
	float GetElapsedTime();

	bool GetIsUsed();
	bool CanUseSkill();

	virtual void Update(float delta, Player* pPlayer) = 0;
	virtual void TriggerSkill(float delta, Player* pPlayer) = 0;
	virtual void OnActivaction(float delta, Player* pPlayer) = 0;
	virtual void SetValues(int lvl) = 0;
};

