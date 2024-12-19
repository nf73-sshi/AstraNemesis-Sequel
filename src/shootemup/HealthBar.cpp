#include "HealthBar.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

HealthBar::HealthBar() : mHpBarFilled(sf::Vector2f(200.f, 30)), mHpBarEmpty(sf::Vector2f(200.f, 30))
{
	mDestroy = false;
	mHpBarFilled.setFillColor(sf::Color::Yellow);
	mHpBarEmpty.setFillColor(sf::Color::Red);
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
	mHpBarFilled.setSize(sf::Vector2f(200.f * ratio, 30));
}