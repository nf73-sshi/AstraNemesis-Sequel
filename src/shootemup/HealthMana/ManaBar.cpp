#include "ManaBar.h"

ManaBar::ManaBar() : mManaBarFilled(sf::Vector2f(250.f, 30)), mManaBarEmpty(sf::Vector2f(250.f, 30))
{
	mDrawPriority = 9;

	mDestroy = false;
	mManaBarFilled.setFillColor(sf::Color::Magenta);
	mManaBarEmpty.setFillColor(sf::Color(162, 0, 255));
}

void ManaBar::Update(float delta)
{
	return;
}

void ManaBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mManaBarEmpty, states);
	target.draw(mManaBarFilled, states);
}

sf::RectangleShape* ManaBar::GetManaBarFilled()
{
	return &mManaBarFilled;
}

sf::RectangleShape* ManaBar::GetManaBarEmpty()
{
	return &mManaBarEmpty;
}

void ManaBar::UpdateBar(float ratio)
{
	mManaBarFilled.setSize(sf::Vector2f(250.f * ratio, 30));
}
