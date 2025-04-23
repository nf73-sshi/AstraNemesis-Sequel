#include "HealthBar.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#include "../Important/GameManager.h"

HealthBar::HealthBar(float length, float width)
{
	mDrawPriority = 4;
	varColor1 = 0.f;
	varColor2 = 255;

	mLength = length;
	mWidth = width;
	mCurrentRatio = 1;

	mHpBarFilled.setSize(sf::Vector2f(mLength, mWidth));
	mHpBarEmpty.setSize(sf::Vector2f(mLength, mWidth));

	mDestroy = false;
	mHpBarFilled.setFillColor(sf::Color::Green); 
	mHpBarEmpty.setFillColor(sf::Color(60, 0, 136));
}

void HealthBar::Update(float delta)
{
	if (mCurrentRatio <= 0.f)
	{
		sf::Color fBar = mHpBarFilled.getFillColor();
		sf::Color eBar = mHpBarEmpty.getFillColor();

		mHpBarFilled.setFillColor(sf::Color(fBar.r, fBar.g, fBar.b, alpha));
		mHpBarEmpty.setFillColor(sf::Color(eBar.r, eBar.g, eBar.b, alpha));

		if (alpha > 0)
			alpha -= 150 * GameManager::GetInstance()->GetDeltaTime();
		else
			alpha = 0.f;
	}

	return;
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mHpBarEmpty, states);
	target.draw(mHpBarFilled, states);  
}

sf::RectangleShape* HealthBar::GetMHpBarFilled()
{
	return &mHpBarFilled;
}

sf::RectangleShape* HealthBar::GetMHpBarEmpty()
{
	return &mHpBarEmpty;
}

void HealthBar::SetBarPosition(float x, float y)
{
	mHpBarFilled.setPosition(x, y);
	mHpBarEmpty.setPosition(x, y);
}

void HealthBar::UpdateBar(float ratio)
{
	mCurrentRatio = ratio;

	const sf::Vector2f finalSize = { mLength * ratio, mWidth };

	float inverseRatio = 1 - ratio;

	if (inverseRatio < 0.5)
		varColor1 = 510 * inverseRatio;
	else
		varColor2 = 510 * ratio;

	mHpBarFilled.setSize(finalSize);

	mHpBarFilled.setFillColor(sf::Color(varColor1, varColor2, 0));
}