#include "SkillBallX2.h"
#include "../PlayerMobs/Player.h"
#include <iostream>

SkillBallX2::SkillBallX2() : Skill(GameManager::GetInstance()->GetStats().GetSkillBallX2Lvl(), 35, 3)
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

		GameManager::GetInstance()->GetCurrentPlayer()->SetShootingDelay(
			GameManager::GetInstance()->GetCurrentPlayer()->GetDefaultSDelay() );
	}

	if (CanUseSkill( *(pPlayer->GetCurrentMana()) ) && mSkillUsed == false)
	{
		mSkillCanBeUsed = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			pPlayer->AddRemoveMana(-mCost);
			mSkillUsed = true;
		}
	}
	else
	{
		mSkillCanBeUsed = false;
	}
}

void SkillBallX2::OnActivaction(float delta, Player* pPlayer) 
{
	GameManager::GetInstance()->GetCurrentPlayer()->SetShootingDelay( 
		GameManager::GetInstance()->GetCurrentPlayer()->GetDefaultSDelay() * mFactor);

	return;
}

void SkillBallX2::SetValues(int lvl)
{
	switch (lvl)
	{
	case 1:
		mFactor = 0.5f;
		break;

	case 2:
		mFactor = 0.44f;
		break;
	
	case 3:
		mFactor = 0.38f;
		break;

	case 4:
		mFactor = 0.32f;
		break;

	case 5:
		mFactor = 0.25f;
		break;

	default:
		mFactor = 0.5f;
		break;

	}
}
