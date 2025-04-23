#include "HealthBar.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

HealthBar::HealthBar(float length, float width)
{
	mLength = length;
	mWidth = width;

	mHpBarFilled.setSize(sf::Vector2f(mLength, mWidth));
	mHpBarEmpty.setSize(sf::Vector2f(mLength, mWidth));

	mDestroy = false;
	mHpBarFilled.setFillColor(sf::Color::Yellow);
	mHpBarEmpty.setFillColor(sf::Color(162, 0, 255));
}

void HealthBar::Update(float delta)
{
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

void HealthBar::UpdateBar(float ratio)
{
	const sf::Vector2f finalSize = { mLength * ratio, mWidth };

	mHpBarFilled.setSize(finalSize);
}