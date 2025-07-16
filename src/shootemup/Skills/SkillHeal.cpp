#include "SkillHeal.h"

SkillHeal::SkillHeal() : Skill(GameManager::Get()->GetStats().GetSkillHealX2Lvl(), 50, 3)
{
	SetValues(mLvl);
}

void SkillHeal::Update(float delta, Player* pPlayer)
{
	TriggerSkill(delta, pPlayer);
}

void SkillHeal::TriggerSkill(float delta, Player* pPlayer)
{
	if (mSkillUsed && mElapsedTime < mDuration)
	{
		OnActivaction(delta, pPlayer);
		mElapsedTime += delta;
	}
	else
	{
		mElapsedTime = 0;
		mSkillUsed = false;
	}

	if (CanUseSkill(*(pPlayer->GetCurrentMana())) && mSkillUsed == false && GameManager::Get()->GetCurrentPlayer()->Health::GetRatioHP() < 1)
	{
		mSkillCanBeUsed = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) 
		{
			pPlayer->AddRemoveMana(-mCost);
			mSkillUsed = true;
			GameManager::Get()->GetCurrentPlayer()->AddRemoveHP(mPower); 

			auto sfx = AssetManager::Get()->GetSound("Heal1");
			sfx->play();
		}
	}
	else
	{
		mSkillCanBeUsed = false;
	}
}

void SkillHeal::OnActivaction(float delta, Player* pPlayer)
{
	return;
}

void SkillHeal::SetValues(int lvl)
{
	switch (lvl)
	{
	case 1:
		mPower = 1;
		break;

	case 2:
		mPower = 1;
		break;

	case 3:
		mPower = 2;
		break;

	case 4:
		mPower = 2;
		break;

	case 5:
		mPower = 3;
		break;

	default:
		mPower = 1;
		break;

	}
}