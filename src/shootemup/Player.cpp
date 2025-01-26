#include "Player.h"
#include "GameManager.h"
#include "Boss1.h"
#include "AllyBall.h"
#include "EnemyBall.h"
#include <typeinfo>
#include <iostream>
#include "SkillBallX2.h"
#include "Skill.h"

Player::Player() : Character("Ship", GameManager::GetInstance()->GetStats().GetPlayerMaxHP(), 
      GameManager::GetInstance()->GetStats().GetPlayerDamage(),
      GameManager::GetInstance()->GetStats().GetPlayerSpeed(),
      GameManager::GetInstance()->GetStats().GetPlayerSDelay() )
{
    mHitboxSize = 8.f;

    mTimerInactive = 0;
    mTimerInvincible = 0;
    mIsInvincible = false;
    mScaleBall = 1;
	CreateSprite("../../../res/assets/Images/vaisseau.png", 0, 0, 64, 64);
    mTimerShoot = 0;

    mMaxMana = GameManager::GetInstance()->GetStats().GetPlayerMaxMana();
    mCurrentMana = mMaxMana;

    s1 = new SkillBallX2();

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

void Player::SetLifeBar(HealthBar* pHB)
{
    mHB = pHB;
}

void Player::Shoot()
{
    if (mTimerInactive < 2)
        return;

    if (mTimerShoot > mShootingDelay) {
        AllyBall* b = new AllyBall(mDamage, 1, mScaleBall, 0, -1000);

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


    if (Health::IsDead())
    {
        mHitboxSize = 0;
        GetHitbox();
        mEndTimer += delta;
        this->sprite.setColor(sf::Color(255, 255, 255, 0));
        if (mEndTimer > 1)
        {
            mDestroy = true;
            GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("GameOver");
        }
        return;
    }

    Move(delta);
    ScreenCollision(); 
    Shoot();

    s1->Update(delta, &mCurrentMana);
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

    if (typeid(*e) == typeid(Boss1)) 
    {
        mIsInvincible = true;
        AddRemoveHP(-1);
        mHB->UpdateBar(Health::GetRatioHP());
    }
}
