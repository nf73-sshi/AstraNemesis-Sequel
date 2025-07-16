#include "ABoss.h"
#include "../Balls/AllyBall.h"
#include "../HealthMana/HealthBar.h"
#include "../PlayerMobs/Player.h"
#include "../Important/GameManager.h"

ABoss::ABoss(const char* name, int hp, int damage, float speed, float shootingDelay, float atkSpeed, float scaleBall) : Character(name, hp, damage, speed, shootingDelay)
{
	mDrawPriority = 7;
	srand(time(0));
	mAtkSpeed = atkSpeed;
	mScaleBall = scaleBall;
	mRandomizer = 0;
}

void ABoss::Update(float delta)
{
	mHB->UpdateBar(Health::GetRatioHP());
}

void ABoss::Randomize()
{
	mRandomizer = rand() % 101;
}

void ABoss::SetLifeBar(HealthBar* pHB)
{
	mHB = pHB;
}

void ABoss::OnCollide(Entity* e)
{
	if (mTimerDelay < 0.001f)
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
