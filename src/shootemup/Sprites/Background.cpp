#include "Background.h"

Background::Background()
{
	mDrawPriority = -4;

	CreateSprite("BackgroundSpace", 0, 0, 1920, 2160);
}

void Background::Update(float delta)
{
	mPos = this->getPosition();

	if (mPos.y >= -10)
	{
		this->setPosition(960, -1080);
	}

	this->move(0, 100 * delta);

}