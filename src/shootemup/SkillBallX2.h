#pragma once
#include "Skill.h"

class SkillBallX2 : public Skill
{
	float mFactor;
public:
	SkillBallX2();

	// Hérité via Skill
	void Update(float delta, int* currentCharge) override;
	void TriggerSkill(float delta, int* currentCharge) override;
	void OnActivaction(float delta, int* currentCharge) override;

	void SetValues(int lvl) override;
};

