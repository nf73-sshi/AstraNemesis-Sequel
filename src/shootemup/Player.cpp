#include "Player.h"
#include "GameManager.h"
#include "Boss1.h"
#include "AllyBall.h"
#include "EnemyBall.h"
#include <typeinfo>
#include <iostream>

Player::Player(const char* name, int hp, int damage, float speed, float shootingDelay) : Character(name, hp, damage, speed, shootingDelay)
{
    mTimerInvincible = 0;
    mIsInvincible = false;
    mPlayerHitbox.setRadius(100.f);
    mPlayerHitbox.setOrigin(10, 10);
    mPlayerHitbox.setFillColor(sf::Color::Yellow);
    mName = name; 
    mDamage = damage;  
    mSpeed = speed; 
    mShootingDelay = shootingDelay; 
	CreateSprite("../../../res/assets/Images/vaisseau.png", 0, 0, 64, 64);
    mTimerShoot = 0;
}

void Player::Move(float delta)
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

void Player::Shoot()
{
    if (mTimerShoot > mShootingDelay) {
        AllyBall* b = new AllyBall(10, 1, 1, 0, -1000);

        b->setOrigin(9, 9);
        b->setPosition(getPosition());
        GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
        mTimerShoot = 0;
    }

    return;
}

void Player::ScreenCollision()
{
    if (this->getPosition().x < 32.f)
        this->setPosition(32, this->getPosition().y); 

    if (this->getPosition().x > 1888.f) 
        this->setPosition(1888, this->getPosition().y); 

    if (this->getPosition().y < 32.f) 
        this->setPosition(this->getPosition().x, 32); 

    if (this->getPosition().y > 1048.f) 
        this->setPosition(this->getPosition().x, 1048);

}

void Player::BeInvincible()
{
    mIsInvincible = true;
}

void Player::ResetInvincible(float delta)
{
    mTimerInvincible += delta; 

    if (mTimerInvincible >= 2) 
    {
        mIsInvincible = false; 
        mTimerInvincible = 0; 
    }
}

void Player::Update(float delta)
{
    mPos = GetPosition();

    mTimerShoot += delta;

    if(mIsInvincible == true)
        ResetInvincible(delta); 

    Move(delta);
    ScreenCollision(); 
    Shoot();

}

Hitbox Player::GetHitbox()
{
    Hitbox h;
    h.position = mPos;
    h.radius = 8.f;

    return h;
}

void Player::OnCollide(Entity* e) 
{
    if (mIsDead == true)
        return;

    if (mIsInvincible == true)
        return;

    if (typeid(*e) == typeid(EnemyBall))
    {
        mIsInvincible = true;
        AddRemoveHP(-1);
        std::cout << "Une boule te fracasse ! : " << mHP << " PV Restants pour toi" << std::endl;
    }

    if (typeid(*e) == typeid(Boss1)) 
    {
        mIsInvincible = true;
        AddRemoveHP(-1);
        std::cout << "Le boss te fracasse ! : " << mHP << " PV Restants pour toi" << std::endl;
    }

    if (IsDead())
    {
        mIsDead = true;
        std::cout << "T'es mort !" << std::endl;
    }

}
