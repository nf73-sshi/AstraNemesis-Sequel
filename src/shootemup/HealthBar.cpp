#include "HealthBar.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

HealthBar::HealthBar() : mHpBar(sf::Vector2f(200, 50))
{
	texture.create(200, 50);
	mHpBar.setTexture(&texture);
	mDestroy = false;
	mHpBar.setFillColor(sf::Color::Yellow);
}

void HealthBar::Update(float delta)
{
	return;
}
