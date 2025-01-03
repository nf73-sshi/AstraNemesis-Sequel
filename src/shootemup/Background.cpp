#include "Background.h"

sf::Vector2f pos;

Background::Background()
{
	CreateSprite("../../../res/assets/Images/spaceHeavyLess.png", 0, 0, 1920, 2160); 
}

void Background::Update(float delta)
{
	pos = this->getPosition();

	if (pos.y >= -10)
	{
		this->setPosition(960, -1080);
	}

	this->move(0, 100 * delta);

}