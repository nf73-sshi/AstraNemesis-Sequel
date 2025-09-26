#include "UI_Skills.h"
#include "../Important/GameManager.h"
#include "../Skills/Skill.h"

UI_Skills::UI_Skills(const char* alias, Skill* owner, int x, int y, int sizeX, int sizeY)
{
	this->alias = alias;
	pOwner = owner;
	mDestroy = false;
	mDrawPriority = 8;
	CreateSprite(alias, x, y, sizeX, sizeY);
}

void UI_Skills::Update(float delta)
{
	if (pOwner == nullptr)
		return;

	if (pOwner->CanUseSkill() == true && pOwner->GetIsUsed() == false)
	{
		sprite.setColor(sf::Color(255, 255, 255));
	}
	else if(pOwner->CanUseSkill() == false && pOwner->GetIsUsed() == false)
	{
		sprite.setColor(sf::Color(150, 150, 150));
	}
	else
	{
		sprite.setColor(sf::Color(0, 255, 255));
	}
}
