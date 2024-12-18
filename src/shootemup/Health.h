#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"

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
	void SetHP(int value);
	void AddRemoveHP(int value);
	bool IsDead();

};

