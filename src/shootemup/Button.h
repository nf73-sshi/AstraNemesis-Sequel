#pragma once
#include "Entity.h"

class Button : public Entity
{

protected:
	sf::Vector2f mPos;
	sf::FloatRect mBoundingBox;
	float mVelocity;
public:
	Button();
	virtual void Update(float delta);
	void Interaction();
};

