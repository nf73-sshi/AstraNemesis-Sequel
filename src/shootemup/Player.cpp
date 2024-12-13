#include "Player.h"
#include "GameManager.h"

Player::Player(const char* name, int hp, int damage, float speed, float shootingDelay) : Character(name, hp, damage, speed, shootingDelay)
{
    mPlayerHitbox.setRadius(100.f);
    mPlayerHitbox.setOrigin(10, 10);
    mPlayerHitbox.setFillColor(sf::Color::Yellow);
    mName = name; 
    mDamage = damage;  
    mSpeed = speed; 
    mShootingDelay = shootingDelay; 
	CreateSprite("../../../res/assets/Images/vaisseau.png", 0, 0, 64, 64);
    mCurrentTimer = 0;
}

void Player::Shoot()
{
    if (mCurrentTimer > 0.1) {
        Ball* b = new Ball(1, 2000, 0);

        b->setOrigin(8.5, 8.5);
        b->setPosition(getPosition());
        GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
        mCurrentTimer = 0;
    }

    return;
}

void Player::Update(float delta)
{
    mPos = GetPosition();
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

    Shoot();

    mCurrentTimer += delta;

    if (this->getPosition().x < 32.f)
        this->setPosition(32, this->getPosition().y);

    if (this->getPosition().x > 1888.f)
        this->setPosition(1888, this->getPosition().y);

    if (this->getPosition().y < 32.f)
        this->setPosition(this->getPosition().x, 32) ;

    if (this->getPosition().y > 1048.f)
        this->setPosition(this->getPosition().x, 1048);

}

Hitbox Player::GetHitbox()
{
    Hitbox h;
    h.position = getPosition();
    h.radius = 8.f;

    return Hitbox();
}

void Player::OnCollide(Entity*)
{
}
