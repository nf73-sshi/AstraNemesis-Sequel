#include "Button.h"

Button::Button()
{
	mVelocity = 100;
	mTimer = 0;
	min = 100;
	rdm = 567;
}

void Button::Update(float delta)
{
	mTimer += delta;
	mPos = getPosition();
	mBoundingBox = sprite.getGlobalBounds();
	mBoundingBox = getTransform().transformRect(mBoundingBox);
}