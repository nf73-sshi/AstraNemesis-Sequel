#pragma once
#include "Skill.h"
class SkillHeal : public Skill
{
	int mPower;
public:
	SkillHeal();
	void Update(float delta, Player* pPlayer) override;
	void TriggerSkill(float delta, Player* pPlayer) override;
	void OnActivaction(float delta, Player* pPlayer) override;
	void SetValues(int lvl) override;
};

