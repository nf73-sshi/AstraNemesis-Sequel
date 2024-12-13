#include "Health.h"

Health::Health(int hpMax)
{
	mHPMax = hpMax;
	mHP = mHPMax;
}

int Health::GetHP()
{
	return mHP;
}

int Health::GetHPMax()
{
	return mHPMax;
}

void Health::SetHP(int value)
{
	mHP = value;

	if (mHP > mHPMax)
		mHP = mHPMax;

	if (mHP <= 0)
	{
		mHP = 0;
	}
}

void Health::AddRemoveHP(int value)
{
	mHP += value;
	if (mHP > mHPMax)
		mHP = mHPMax;

	if (mHP <= 0)
	{
		mHP = 0;
	}
}

bool Health::IsDead() 
{
	if (mHP <= 0)
		return true;

	return false;
}
