#include "Mob.h"
#include "../Balls/EnemyBall.h"
#include "../Balls/AllyBall.h"
#include "Player.h"
#include "../Important/GameManager.h"

Mob::Mob(const char* name, int hp, int damage, float speed, float shootingDelay) : Character(name, hp, damage, speed, shootingDelay)
{
	mVelocityX = mSpeed;
	mVelocityY = mSpeed;
}


void Mob::Update(float delta)
{
	mTimerShoot += delta;
	mTimerDelay += delta;

	Shoot();

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

Hitbox Mob::GetHitbox()
{
	Hitbox h;
	h.position = getPosition();
	h.radius = 75;
	return h;
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