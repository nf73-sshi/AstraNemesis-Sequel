#include "Stats.h"

void Stats::SetPlayerMaxMana(int value)
{
    mPlayerMaxMana = value;

    if (mPlayerMaxMana < 0)
        mPlayerMaxMana = 0;

    FillMana();
}
void Stats::SetPlayerMana(int value)
{
    mPlayerCurrentMana = value;
}
void Stats::SetMoney(int value)
{
    mMoney = value;
}
void Stats::SetSkillBallX2Lvl(int value)
{
    mSkillBallX2Lvl = value;
}
void Stats::SetPlayerMaxHP(int value)
{
    mPlayerMaxHP = value;

    FillHP();
}
void Stats::SetPlayerHP(int value)
{
    mPlayerCurrentHP = value;
}
void Stats::SetPlayerDamage(int value)
{
    mPlayerDamage = value;
}
void Stats::SetPlayerSpeed(float value)
{
    mPlayerSpeed = value;
}
void Stats::SetPlayerSDelay(float value)
{
    mPlayerSDelay = value;
}
void Stats::SetPlayerManaReload(float value)
{
    mPlayerManaReload = value;

    if (mPlayerManaReload <= 0)
    {
        mPlayerManaReload = 0.01f;
    }
}

void Stats::AddPlayerMaxMana(int value)
{
    mPlayerMaxMana += value;

    if (mPlayerMaxMana < 0)
        mPlayerMaxMana = 0;

    FillMana(); 
}
void Stats::AddPlayerMana(int value)
{
    mPlayerCurrentMana += value;

    if (mPlayerCurrentMana < 0)
        mPlayerCurrentMana = 0;

    if (mPlayerCurrentMana > mPlayerMaxMana)
        mPlayerCurrentMana = mPlayerMaxMana;
}
void Stats::AddMoney(int value)
{
    mMoney += value;

    if (mMoney < 0)
        mMoney = 0;
}
void Stats::AddSkillBallX2Lvl(int value)
{
    mMoney += value;

    if (mMoney < 0)
        mMoney = 0;
}
void Stats::AddPlayerMaxHP(int value)
{
    mPlayerMaxHP += value;

    if (mPlayerMaxHP < 0)
        mPlayerMaxHP = 0;

    FillHP();
}
void Stats::AddPlayerHP(int value)
{
    mPlayerCurrentHP += value;

    if (mPlayerCurrentHP < 0)
        mPlayerCurrentHP = 0;

    if (mPlayerCurrentHP > mPlayerMaxHP)
        mPlayerCurrentHP = mPlayerMaxHP;
}
void Stats::AddPlayerDamage(int value)
{
    mPlayerDamage += value;

    if (mPlayerDamage < 0)
        mPlayerDamage = 0;
}
void Stats::AddPlayerSpeed(float value)
{
    mPlayerSpeed += value;

    if (mPlayerSpeed < 0) 
        mPlayerSpeed = 0; 
}
void Stats::AddPlayerSDelay(float value)
{
    mPlayerSDelay += value;

    if (mPlayerSDelay < 0.001f) 
        mPlayerSDelay = 0.001f;
}
void Stats::AddRemovePlayerManaReload(float value)
{
    mPlayerManaReload += value;

    if (mPlayerManaReload <= 0)
    {
        mPlayerManaReload = 0.01f;
    }
}

void Stats::FillMana()
{
    mPlayerCurrentHP = mPlayerMaxHP;
}
void Stats::FillHP()
{
    mPlayerCurrentMana = mPlayerMaxMana;
}

