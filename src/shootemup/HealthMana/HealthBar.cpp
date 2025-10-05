#include "HealthBar.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#include "../Important/GameManager.h"

HealthBar::HealthBar(float length, float width)
{
	mDrawPriority = 9;
	mDestroy = false;

	varColor1 = 0.f;
	varColor2 = 255;

	mLength = length;
	mWidth = width;
	mCurrentRatio = 1;

	mHpBarFilled.setSize(sf::Vector2f(mLength, mWidth));
	mHpBarEmpty.setSize(sf::Vector2f(mLength, mWidth));
	mLight.setSize(sf::Vector2f(mLength, mWidth * 0.10f));
	mShadow.setSize(sf::Vector2f(mLength, mWidth * 0.15f));

	mHpBarFilled.setFillColor(sf::Color::Green); 
	mHpBarEmpty.setFillColor(sf::Color(60, 0, 136));
	mLight.setFillColor(sf::Color(255, 255, 255, 100));
	mShadow.setFillColor(sf::Color(0, 0, 0, 100));
}

void HealthBar::Update(float delta)
{
	if (showAfterDying == true)
		return;

	if (mCurrentRatio <= 0.f)
	{
		if (fading == true && alpha > 0)
		{
			sf::Color fBar = mHpBarFilled.getFillColor();
			sf::Color eBar = mHpBarEmpty.getFillColor();

			mHpBarFilled.setFillColor(sf::Color(fBar.r, fBar.g, fBar.b, alpha));
			mHpBarEmpty.setFillColor(sf::Color(eBar.r, eBar.g, eBar.b, alpha));
			mLight.setFillColor(sf::Color(255, 255, 255, alpha));
			mShadow.setFillColor(sf::Color(0, 0, 0, alpha));

			alpha -= 150 * GameManager::Get()->GetDeltaTime();
		}
		else
		{
				SetMDestroy(true);
		}
	}

	return;
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mHpBarEmpty, states);
	target.draw(mHpBarFilled, states);  
	target.draw(mLight, states);
	target.draw(mShadow, states);
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
	mLight.setPosition(x, y);
	mShadow.setPosition(x, y + mHpBarFilled.getGlobalBounds().height - mShadow.getGlobalBounds().height);
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