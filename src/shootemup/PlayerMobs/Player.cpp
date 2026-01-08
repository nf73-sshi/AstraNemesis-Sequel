#include "Player.h"
#include "../Important/GameManager.h"
#include "../Important/AssetManager.h"
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

Player::Player() : Character("Ship", GameManager::Get()->GetStats().GetPlayerMaxHP(),
	GameManager::Get()->GetStats().GetPlayerDamage(),
	GameManager::Get()->GetStats().GetPlayerSpeed(),
	GameManager::Get()->GetStats().GetPlayerSDelay()), Mana()
{
	mDrawPriority = 5;

	mHitboxSize = 10.f;

	mTimerInactive = 0;
	mTimerInvincible = 0;
	mIsInvincible = false;
	mScaleBall = 1;
	CreateSprite("Player", 0, 0, 64, 64);
	mTimerShoot = 0;

	skillArray["SkillBallX2"] = new SkillBallX2();
	skillArray["SkillHeal"] = new SkillHeal();
}

void Player::Move()
{
	float dt = GameManager::Get()->GetDeltaTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		this->move(0.f, -mSpeed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(0.f, mSpeed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		this->move(-mSpeed * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(mSpeed * dt, 0);
	}
}

void Player::DebugFeatures()
{
	if (GameManager::Get()->GetIsDebugMod() == false)
		return;

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
		angleFactor -= 15.f * GameManager::Get()->GetDeltaTime();
		AddRemoveShootingDelay(-1.f);
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
	float dt = GameManager::Get()->GetDeltaTime();

	if (mTimerInactive < 2)
	{
		mTimerInactive += dt; 
		return;
	}

	if (mIsInvincible == true)
		return;

	mTimerShoot += dt;

	if (mTimerShoot > mShootingDelay) {
		AllyBall* b = new AllyBall(mDamage, 1, mScaleBall, std::cos(PI * angleFactor) * 1000, std::sin(PI * angleFactor) * -1000);

		b->setPosition(this->getPosition());
		GameManager::Get()->GetCurrentScene()->addEntity(b);
		mTimerShoot = 0;

		AssetManager::Get()->GetSound("Laser1")->play();
	}

	return;
}

void Player::ScreenCollision()
{
	sf::Vector2f spriteSize = GetSpriteSize();

	float halfSize = spriteSize.x / 2; // Square Sprite

	if (this->getPosition().x < halfSize)
		this->setPosition(halfSize, this->getPosition().y);

	if (this->getPosition().x > WINDOW_WIDTH - halfSize - 300) // 150 = size of the UI
		this->setPosition(WINDOW_WIDTH - halfSize - 300, this->getPosition().y);

	if (this->getPosition().y < halfSize + 40.f) // 40 = size of the HP Bar of the Boss
		this->setPosition(this->getPosition().x, halfSize + 40.f);

	if (this->getPosition().y > WINDOW_HEIGHT - halfSize)
		this->setPosition(this->getPosition().x, WINDOW_HEIGHT - halfSize);

}

void Player::InvincibleAnim()
{
	this->sprite.setColor(sf::Color(132, 255, 255, 255));
}

void Player::ResetInvincible()
{
	InvincibleAnim();

	mTimerInvincible += GameManager::Get()->GetDeltaTime();

	if (mTimerInvincible < 1)
		return;

	mIsInvincible = false;
	mTimerInvincible = 0;
	this->sprite.setColor(sf::Color(255, 255, 255, 255));
}


void Player::Update(float delta)
{
	if (mIsInvincible == true)
	{
		ResetInvincible();
	}

	if (Health::IsDead())
	{
		AssetManager::Get()->GetSound("Game Over")->play();
		mDestroy = true;
		return;
	}

	DebugFeatures();
	Move();
	ScreenCollision();
	Shoot();
	SkillManager();

	mHB->UpdateBar(Health::GetRatioHP());
	mManaBar->UpdateBar(Mana::GetRatioMana());

	FillManaBar();
}

bool Player::GetIsInvincible()
{
	return mIsInvincible;
}

void Player::SetInvincible(bool value)
{
	mIsInvincible = value;
}

void Player::SkillManager()
{
	float dt = GameManager::Get()->GetDeltaTime();

	Skill* usedSkill = nullptr;

	for (auto it = skillArray.begin(); it != skillArray.end(); ++it)
	{
		if (it->second->GetIsUsed())
		{
			usedSkill = it->second;
			break;
		}
	}

	if (usedSkill != nullptr)
	{
		usedSkill->Update(dt, this);
	}
	else
	{
		for (auto it = skillArray.begin(); it != skillArray.end(); ++it)
		{
			it->second->Update(dt, this);
		}
	}

}

std::vector<Hitbox> Player::GetHitboxes()
{
	return { Hitbox(getPosition(), mHitboxSize * GetMaxScale(), {0, 7.f * GetMaxScale()}) };
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

		AddRemoveMana(GetMaxMana() * 0.1f);
		AssetManager::Get()->GetSound("Hit2")->play();
	}
}
