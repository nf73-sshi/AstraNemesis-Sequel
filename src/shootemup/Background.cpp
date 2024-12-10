#include "Background.h"

sf::Vector2f pos;

Background::Background()
{
	CreateSprite("../../../res/assets/Images/spaceHeavyLess.png", 0, 0, 1920, 2160); 
}

void Background::Update(float delta)
{
	if (pos.y >= -10)
	{
		this->setPosition(960, -1080);
	}

	pos = this->getPosition();

	this->move(0, 100 * delta);

}