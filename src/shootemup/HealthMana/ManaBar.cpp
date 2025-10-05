#include "ManaBar.h"

ManaBar::ManaBar(float length, float width)
{
	mDrawPriority = 9;
	mDestroy = false;
	mLength = length;
	mWidth = width;

	mManaBarFilled.setSize(sf::Vector2f(mLength, mWidth));
	mManaBarEmpty.setSize(sf::Vector2f(mLength, mWidth));
	mLight.setSize(sf::Vector2f(mLength, mWidth * 0.1f));
	mShadow.setSize(sf::Vector2f(mLength, mWidth * 0.15f));

	mManaBarFilled.setFillColor(sf::Color::Magenta);
	mManaBarEmpty.setFillColor(sf::Color(162, 0, 255));
	mLight.setFillColor(sf::Color(255, 255, 255, 100));
	mShadow.setFillColor(sf::Color(0, 0, 0, 100));
}

void ManaBar::Update(float delta)
{
	return;
}

void ManaBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mManaBarEmpty, states);
	target.draw(mManaBarFilled, states);
	target.draw(mLight, states);
	target.draw(mShadow, states);
}

sf::RectangleShape* ManaBar::GetManaBarFilled()
{
	return &mManaBarFilled;
}

sf::RectangleShape* ManaBar::GetManaBarEmpty()
{
	return &mManaBarEmpty;
}

void ManaBar::SetBarPosition(float x, float y)
{
	mManaBarEmpty.setPosition(x, y);
	mManaBarFilled.setPosition(x, y);
	mLight.setPosition(x, y);
	mShadow.setPosition(x, y + mManaBarFilled.getGlobalBounds().height - mShadow.getGlobalBounds().height);
}

void ManaBar::UpdateBar(float ratio)
{
	mManaBarFilled.setSize(sf::Vector2f(mLength * ratio, mWidth));
}
