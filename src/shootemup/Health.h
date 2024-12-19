#pragma once
<<<<<<< Updated upstream
=======
#include "SFML/Graphics.hpp"
>>>>>>> Stashed changes

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

