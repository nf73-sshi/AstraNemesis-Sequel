#include "UI_Skills.h"
#include "../Important/GameManager.h"

UI_Skills::UI_Skills(const char* alias, int x, int y, int sizeX, int sizeY)
{
	this->alias = alias;
	mDestroy = false;
	mDrawPriority = 8;
	CreateSprite(alias, x, y, sizeX, sizeY);

	pOwner = GameManager::Get()->GetCurrentPlayer();
}

void UI_Skills::Update(float delta)
{
	if (pOwner == nullptr)
		return;
}
