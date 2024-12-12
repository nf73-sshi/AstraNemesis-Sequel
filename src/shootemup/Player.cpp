#include "Player.h"

Player::Player(const char* name, int damage, float speed, float shootingDelay) : Character(name, damage, speed, shootingDelay)
{
    mName = name; 
    mDamage = damage; 
    mSpeed = speed; 
    mShootingDelay = shootingDelay; 
	CreateSprite("../../../res/assets/Images/vaisseau.png", 0, 0, 64, 64);
}

void Player::Shoot()
{
    return;
}

void Player::Update(float delta)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->move(0.f, -mSpeed * delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->move(0.f, mSpeed * delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->move(-mSpeed * delta, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->move(mSpeed * delta, 0);
    }
}