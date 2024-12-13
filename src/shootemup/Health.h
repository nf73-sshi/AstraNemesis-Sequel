#pragma once

class Health
{

protected:
	int mHP;
	int mHPMax;

public:
	Health(int hpMax);

	int GetHP();
	int GetHPMax();
	void SetHP(int value);
	void AddRemoveHP(int value);
	bool IsDead();



};

