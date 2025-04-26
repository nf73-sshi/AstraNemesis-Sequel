#include "UI.h"

UI::UI()
{
	mDestroy = false;
	mDrawPriority = 8;
	CreateSprite("UI", 0, 0, 150, 540);
}

void UI::Update(float delta)
{
	return;
}
