#include "Mana.h"
#include "../Important/GameManager.h"

Mana::Mana()
{
    auto stats = GameManager::Get()->GetStats();
    mMaxMana = stats.GetPlayerMaxMana(); 
    mCurrentMana = stats.GetPlayerMana();
    mManaReload = stats.GetPlayerManaReload();  
}

void Mana::FillManaBar(float dt)
{
    mProgress += dt;

    if (mProgress > mManaReload)
    {
        AddRemoveMana(1);
        mProgress = 0;
    }
}

int* Mana::GetCurrentMana()
{
    return &mCurrentMana;
}
void Mana::SetCurrentMana(int value)
{
    mCurrentMana = value;

    if (mCurrentMana > mMaxMana)
    {
        mCurrentMana = mMaxMana;
    }
}
void Mana::AddRemoveMana(int value)
{
    mCurrentMana += value;

    if (mCurrentMana > mMaxMana)
    {
        mCurrentMana = mMaxMana;
    }

    if (mCurrentMana < 0)
    {
        mCurrentMana = 0;
    }
}

int Mana::GetMaxMana()
{
    return mMaxMana;
}
void Mana::SetMaxMana(float value)
{
    mMaxMana = value;

    if (mMaxMana < 0)
    {
        mMaxMana = 0;
    }
}
void Mana::AddRemoveMaxMana(int value)
{
    mMaxMana += value;

    if (mMaxMana < 0)
    {
        mMaxMana = 0;
    }
}

float Mana::GetRatioMana()
{
    return ((float) mCurrentMana / (float) mMaxMana);
}

float Mana::GetManaReload()
{
    return mManaReload;
}
void Mana::SetManaReload(float value)
{
    mManaReload = value;

    if (mManaReload <= 0)
    {
        mManaReload = 0.01f;
    }
}
void Mana::AddRemoveManaReload(float value)
{
    mManaReload += value;

    if (mManaReload <= 0)
    {
        mManaReload = 0.01f;
    }
}
