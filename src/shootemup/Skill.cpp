#include "Skill.h"

Skill::Skill(int cost, float duration)
{
    mCost = cost;
    mTimeElapsed = 0;
	mDuration = duration;
	mSkillUsed = false;
}

float Skill::GetCost()
{
    return mCost;
}

bool Skill::UseSkill(int cost, int currentCharge) 
{
    if(cost < currentCharge)
        return false;

    return true;
}
