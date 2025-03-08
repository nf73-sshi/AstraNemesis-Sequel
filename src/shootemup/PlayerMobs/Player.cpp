#include "Player.h"
#include "../Important/GameManager.h"
#include "../Bosses/ABoss.h"
#include <cmath>
#include "../Balls/AllyBall.h"
#include "../Balls/EnemyBall.h"
#include <typeinfo>
#include <iostream>
#include "../Skills/SkillBallX2.h"
#include "../Skills/SkillHeal.h"
#include "../Skills/Skill.h"

bool rotatemod = false;
float angleFactor = 0.5f;

Player::Player() : Character("Ship", GameManager::GetInstance()->GetStats().GetPlayerMaxHP(),
    GameManager::GetInstance()->GetStats().GetPlayerDamage(),
    GameManager::GetInstance()->GetStats().GetPlayerSpeed(),
    GameManager::GetInstance()->GetStats().GetPlayerSDelay()), Mana()
{


    mHitboxSize = 8.f;

    mTimerInactive = 0;
    mTimerInvincible = 0;
    mIsInvincible = false;
    mScaleBall = 1;
	CreateSprite("res/assets/Images/vaisseau.png", 0, 0, 64, 64);
    mTimerShoot = 0;

    s1 = new SkillBallX2();
    s2 = new SkillHeal();

}

void Player::Move(float delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->move(0.f, -mSpeed * delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(0.f, mSpeed * delta);
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->move(-mSpeed * delta, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(mSpeed * delta, 0);
    }

    if (GameManager::GetInstance()->GetIsDebugMod())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            rotatemod = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        {
            rotatemod = false;
            angleFactor = 0.5f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) 
        {
            AddRemoveShootingDelay(-1.f); 
        }


        if (rotatemod)
        {
            angleFactor -= 15.f * delta;
            AddRemoveShootingDelay(-1.f);
        }
    }

}

void Player::SetLifeBar(HealthBar* pHB)
{
    mHB = pHB;
}

void Player::SetManaBar(ManaBar* pManaBar)
{
    mManaBar = pManaBar; 
}

void Player::Shoot()
{
    if (mTimerInactive < 2)
        return;

    if (mTimerShoot > mShootingDelay) {
        AllyBall* b = new AllyBall(mDamage, 1, mScaleBall, std::cos(PI * angleFactor) * 1000, std::sin(PI * angleFactor) * -1000);

        b->setOrigin(9.f, 9.f);
        b->setPosition(this->getPosition());
        GameManager::GetInstance()->GetCurrentScene()->addEntity(b);
        mTimerShoot = 0;
    }

    return;
}

void Player::ScreenCollision()
{
    if (this->getPosition().x < 32.f)
        this->setPosition(32, this->getPosition().y); 

    if (this->getPosition().x > 1588.f) 
        this->setPosition(1588, this->getPosition().y); 

    if (this->getPosition().y < 32.f) 
        this->setPosition(this->getPosition().x, 32); 

    if (this->getPosition().y > 1048.f) 
        this->setPosition(this->getPosition().x, 1048);

}

void Player::InvincibleAnim(float delta)
{
    this->sprite.setColor(sf::Color(132, 255, 255, 255));
}

void Player::ResetInvincible(float delta)
{
    InvincibleAnim(delta);

    mTimerInvincible += delta;

    if (mTimerInvincible < 1)
        return;

    mIsInvincible = false;
    mTimerInvincible = 0;
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
}


void Player::Update(float delta)
{
    mPos = GetPosition();


    mTimerShoot += delta;

    if (mTimerInactive < 2)
    {
        mTimerInactive += delta;
    }

    if (mIsInvincible == true)
    {
        ResetInvincible(delta);
    }

    if (Health::IsDead())
    {
        mDestroy = true;
        return;
    }

    Move(delta);
    ScreenCollision(); 
    Shoot();

    mHB->UpdateBar(Health::GetRatioHP()); 
    mManaBar->UpdateBar(Mana::GetRatioMana());
    
    FillManaBar(delta);

    s1->Update(delta, this);
    s2->Update(delta, this);
}

bool Player::GetIsInvincible()
{
    return mIsInvincible;
}

void Player::SetInvincible(bool value)
{
    mIsInvincible = value; 
}

Hitbox Player::GetHitbox()
{
    Hitbox h;
    h.position = mPos;
    h.radius = mHitboxSize;

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
        mHB->UpdateBar(Health::GetRatioHP());
    }
}
