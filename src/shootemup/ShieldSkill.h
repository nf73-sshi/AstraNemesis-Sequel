#pragma once
#include "Skill.h"

class ShieldSkill : public Skill
{

public:
	ShieldSkill();

	void UseSkill(float delta) override;

};

