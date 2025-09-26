#pragma once
#include "../Others/Entity.h"

class Skill;

class UI_Skills : public Entity
{
	Skill* pOwner = nullptr;
	const char* alias = "";
public:
	UI_Skills(const char* alias, Skill* owner, int x = -1, int y = -1, int sizeX = -1, int sizeY = -1);
	void Update(float delta) override;
};

