#pragma once
#include "Enemy.h"

class Enemy1 : public Enemy
{

public:
	Enemy1(const char* name, float speed, int damage, float shootingDelay);
};

