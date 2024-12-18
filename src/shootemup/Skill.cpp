#include "Skill.h"

Skill::Skill(float reloadTimer, float duration)
{
	mReloadTimer = reloadTimer;
	mDuration = duration;
	mSkillUsed = false;
}

void Skill::TriggerSkill()
{
    if (mReloadTimer >= 0)
        return;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mSkillUsed = true;
    }
}

bool Skill::UseSkill(float delta, float skillDuration)
{
    if (mSkillUsed == false)
    {
        return false;
    }

    if (mDuration <= 0)
    {
        mSkillUsed = false;
        mDuration = skillDuration;
        return false;
    }
    else
    {
        mDuration -= delta;
        mReloadTimer = 15;
    }

}
