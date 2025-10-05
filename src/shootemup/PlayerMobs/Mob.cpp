#include "Mob.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "Player.h"
#include "../Important/GameManager.h"

constexpr float BAR_FACTOR = 0.5f;

Mob::Mob(const char* name, int hp, int damage, float speed, float shootingDelay) : Character(name, hp, damage, speed, shootingDelay)
{
	mVelocityX = mSpeed;
	mVelocityY = mSpeed;
}

void Mob::Update(float delta)
{
	mTimerShoot += delta;
	mTimerDelay += delta;

	if (mHB)
	{
		sf::Vector2f spriteSize = GetSpriteSize();

		mHB->UpdateBar(Health::GetRatioHP());
		mHB->SetBarPosition(getPosition().x - spriteSize.x * BAR_FACTOR * 0.5f, getPosition().y - 5 - spriteSize.y * 0.5f);
	}
	else
	{
		SetLifeBar();
	}

	if (Health::IsDead() == true)
	{
		AssetManager::Get()->GetSound("Die1")->play();
		Player* p = GameManager::Get()->GetCurrentPlayer(); 

		if (p != nullptr)
		{
			p->AddRemoveMana(manaReward);
		}

		mDestroy = true;
		return;
	}
}

void Mob::SetLifeBar()
{
	sf::Vector2f spriteSize = GetSpriteSize();
	HealthBar* pMobHB = new HealthBar(spriteSize.x * BAR_FACTOR, 8.f);
	mHB = pMobHB;
	mHB->fading = false;
	GameManager::Get()->GetCurrentScene()->addEntity(mHB);
}

void Mob::OnCollide(Entity* e)
{
	if (mTimerDelay < 0.01)
		return;

	if (typeid(*e) == typeid(AllyBall))
	{
		AddRemoveHP(-e->GetDamage());
		mTimerDelay = 0;
	}

	if (typeid(*e) == typeid(Player))
	{
		Player* currentPlayer = GameManager::Get()->GetCurrentPlayer();

		if (currentPlayer->GetIsInvincible() == true)
			return;


		currentPlayer->SetInvincible(true);
		currentPlayer->AddRemoveHP(-1);
		AssetManager::Get()->GetSound("Hit2")->play();
	}
}