#pragma once
#include "Player.h"

class Skill
{

protected:
	int mCost;
	float mTimeElapsed;
	float mDuration;
	bool mSkillUsed;

public:
	Skill(int cost, float duration);

	float GetCost();
	float GetDuration();

	bool GetIsUsed();

	virtual void TriggerSkill() = 0;
	bool UseSkill(int cost, int currentCharge); 
	virtual void OnActivaction() = 0;

};

