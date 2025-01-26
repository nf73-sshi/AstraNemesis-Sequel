#include "SkillBallX2.h"
#include <iostream>

SkillBallX2::SkillBallX2() : Skill(GameManager::GetInstance()->GetStats().GetSkillBallX2Lvl(), 2, 3)
{
	mFactor = 0;

	SetValues(mLvl);
}

void SkillBallX2::Update(float delta, int* currentCharge)
{
	std::cout << "mFactor = " << mFactor << std::endl;
	TriggerSkill(delta, currentCharge); 
}

void SkillBallX2::TriggerSkill(float delta, int* currentCharge)
{
	if (mSkillUsed && mElapsedTime < mDuration)
	{
		OnActivaction(delta, currentCharge);
		mElapsedTime += delta;
	}
	else
	{
		mElapsedTime = 0;
		mSkillUsed = false;

		GameManager::GetInstance()->GetCurrentPlayer()->SetShootingDelay(
			GameManager::GetInstance()->GetCurrentPlayer()->GetDefaultSDelay() );
	}

	if (CanUseSkill(*currentCharge) && mSkillUsed == false)
	{
		mSkillCanBeUsed = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			// *currentCharge -= mCost;
			mSkillUsed = true;
		}
	}
	else
	{
		mSkillCanBeUsed = false;
	}
}

void SkillBallX2::OnActivaction(float delta, int* currentCharge)
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
