#include "SkillBallX2.h"
#include "../PlayerMobs/Player.h"
#include "../Important/AssetManager.h"
#include <iostream>

SkillBallX2::SkillBallX2() : Skill(GameManager::Get()->GetStats().GetSkillBallX2Lvl(), 30, 3)
{
	mFactor = 0;

	SetValues(mLvl);
}

void SkillBallX2::Update(float delta, Player* pPlayer)
{
	TriggerSkill(delta, pPlayer);  
}

void SkillBallX2::TriggerSkill(float delta, Player* pPlayer)
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

		GameManager::Get()->GetCurrentPlayer()->SetShootingDelay(
			GameManager::Get()->GetCurrentPlayer()->GetDefaultSDelay() );
	}

	if (CanUseSkill( *(pPlayer->GetCurrentMana()) ) && mSkillUsed == false)
	{
		mSkillCanBeUsed = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			pPlayer->AddRemoveMana(-mCost);
			mSkillUsed = true;

			auto sfx = AssetManager::Get()->GetSound("Boost1");
			sfx->play();
		}
	}
	else
	{
		mSkillCanBeUsed = false;
	}
}

void SkillBallX2::OnActivaction(float delta, Player* pPlayer) 
{
	GameManager::Get()->GetCurrentPlayer()->SetShootingDelay( 
		GameManager::Get()->GetCurrentPlayer()->GetDefaultSDelay() * mFactor);

	return;
}

void SkillBallX2::SetValues(int lvl)
{
	switch (lvl)
	{
	case 1:
		mFactor = 0.75f;
		break;

	case 2:
		mFactor = 0.7f;
		break;
	
	case 3:
		mFactor = 0.63f;
		break;

	case 4:
		mFactor = 0.57f;
		break;

	case 5:
		mFactor = 0.50f;
		break;

	default:
		mFactor = 0.75f;
		break;

	}
}