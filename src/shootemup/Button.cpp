#include "Button.h"
#include <iostream>

Button::Button()
{
	mVelocity = 100;
}

void Button::Update(float delta)
{
	mPos = getPosition();
	mBoundingBox = sprite.getGlobalBounds();
	mBoundingBox = getTransform().transformRect(mBoundingBox);
}

void Button::Interaction()
{
}
