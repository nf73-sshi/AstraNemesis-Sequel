#include "Skill.h"

Skill::Skill(int lvl, int cost, float duration)
{
    mLvl = lvl;
    mCost = cost;
    mElapsedTime = 0;
	mDuration = duration;
    mSkillCanBeUsed = false;
	mSkillUsed = false;
}

int Skill::GetLvl()
{
    return mLvl;
}

float Skill::GetCost()
{
    return mCost;
}

float Skill::GetDuration()
{
    return mDuration;
}

float Skill::GetElapsedTime()
{
    return mElapsedTime;
}

bool Skill::GetIsUsed()
{
    return mSkillUsed;
}

bool Skill::CanUseSkill() 
{
    int currentCharge = *(GameManager::Get()->GetCurrentPlayer()->GetCurrentMana());

    if (currentCharge < mCost)
    {
        mSkillCanBeUsed = false;
    }
    else
        mSkillCanBeUsed = true;

    return mSkillCanBeUsed;
}
