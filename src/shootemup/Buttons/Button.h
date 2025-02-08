#pragma once
#include "../Others/Entity.h"

class Button : public Entity
{

protected:
	sf::Vector2f mPos;
	sf::FloatRect mBoundingBox;
	float mVelocity;
	int min;
	int rdm;
	float mTimer;

public:
	Button();
	virtual void Update(float delta);
};

