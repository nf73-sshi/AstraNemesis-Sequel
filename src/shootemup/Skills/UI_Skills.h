#pragma once
#include "../Others/Entity.h"

class Player;

class UI_Skills : public Entity
{
	Player* pOwner = nullptr;
	const char* alias = "";
public:
	UI_Skills(const char* alias, int x = -1, int y = -1, int sizeX = -1, int sizeY = -1);
	void Update(float delta) override;
};

