#pragma once
#include "Ball.h"


class AllyBall : public Ball 
{

public:
	AllyBall(int damage, float speed, float scale, float xFactor, float yFactor); 

	int GetDamage();

	void OnCollide(Entity* e) override;
};

