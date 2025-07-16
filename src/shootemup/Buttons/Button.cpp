#include "Button.h"
#include "../Important/GameManager.h"
#include "../Important/AssetManager.h"

Button::Button()
{
	mDrawPriority = 2;

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

bool Button::IsClicked()
{
	sf::RenderWindow* w = GameManager::Get()->GetWindow();

	sf::Vector2f mousePos = w->mapPixelToCoords(sf::Mouse::getPosition(*w));

	if (mBoundingBox.contains(mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			AssetManager::Get()->GetSound("Beep")->play();
			return true;
		}
	}

	return false;
}
