#include "HealthBarEnemy.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

HealthBarEnemy::HealthBarEnemy() : mHpBar(sf::Vector2f(200, 50))
{
	mDestroy = false;
	mHpBar.setFillColor(sf::Color::Red);
	setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 150);
}

void HealthBarEnemy::Update(float delta)
{
	return;
}

void HealthBarEnemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mHpBar, states);
}
