#pragma once
#include "Player.h"

class Skill
{

protected:
	float mReloadTimer;
	float mDuration;
	bool mSkillUsed;

public:
	Skill(float reloadTimer, float duration);

	void TriggerSkill();
	bool UseSkill(float delta, float skillDuration);

};

