#pragma once
#include "Skill.h"

class Player;

class SkillBallX2 : public Skill
{
	float mFactor;
public:
	SkillBallX2();

	// Hérité via Skill
	void Update(float delta, Player* pPlayer) override; 
	void TriggerSkill(float delta, Player* pPlayer) override; 
	void OnActivaction(float delta, Player* pPlayer) override; 

	void SetValues(int lvl) override;
};

