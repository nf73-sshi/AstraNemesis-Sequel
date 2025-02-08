#pragma once
#include "SFML/Graphics.hpp"

class Health
{

protected:
	int mHP;
	int mHPMax;
	bool mIsDead;

public:
	Health(int hpMax);

	int GetHP();
	int GetHPMax();
	float GetRatioHP();
	void SetHP(int value);
	void AddRemoveHP(int value);
	bool IsDead();

};

