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



    if (this->getPosition().x < 32.f)
        this->setPosition(32, this->getPosition().y);

    if (this->getPosition().x > 1888.f)
        this->setPosition(1888, this->getPosition().y);

    if (this->getPosition().y < 32.f)
        this->setPosition(this->getPosition().x, 32) ;

    if (this->getPosition().y > 1048.f)
        this->setPosition(this->getPosition().x, 1048);
}