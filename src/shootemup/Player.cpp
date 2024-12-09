#include "Player.h"

Player::Player(const char* name, int damage, float speed, float shootingDelay)
{
	mName = name;
	mDamage = damage;
	mSpeed = speed;
	mShootingDelay = shootingDelay;
	CreateSprite("../../../res/assets/Images/vaisseau.png", 0, 0, 64, 64);
}

void Player::Update(float delta)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        move(0.f, -mSpeed * delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        move(0.f, mSpeed * delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        move(-mSpeed * delta, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        move(mSpeed * delta, 0);
    }

}