#include "Background.h"
#include "../Important/res.h"
#include "../Important/GameManager.h"
#include "../Others/Convert.h"

Background::Background()
{
	mDrawPriority = 0;

	CreateSprite("BackgroundSpace", 0, 0, 1920, 2160);

	setPosition(WINDOW_WIDTH * 0.5, 0);
}

void Background::Update(float delta)
{
	if (getPosition().y >= Convert::AdaptToWindow(WINDOW_HEIGHT - 10))
	{
		this->setPosition(WINDOW_WIDTH * 0.5, 0);
	}

	this->move(0, 100 * delta);
}