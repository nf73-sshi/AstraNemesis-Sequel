#include "Background.h"
#include <iostream>

sf::Vector2f pos;

Background::Background()
{
	CreateSprite("../../../res/assets/Images/spaceHeavy.png", 0, 0, 3840, 4380); 
}

void Background::Update(float delta)
{
	if (pos.y >= -21)
	{
		this->setPosition(960, -1080);
	}

	pos = this->getPosition();
	
	std::cout << "restaring in : " << -1 * pos.y << std::endl;

	this->move(0, 100 * delta);

}