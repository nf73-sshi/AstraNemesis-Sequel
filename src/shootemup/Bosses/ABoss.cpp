#include "ABoss.h"
#include "../Balls/AllyBall.h"
#include "../HealthMana/HealthBar.h"
#include "../PlayerMobs/Player.h"
#include "../Important/GameManager.h"
#include "../Balls/EnemyBall.h"

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

	if (Health::IsDead())
	{
		AssetManager::Get()->GetSound("Explosion1")->play();
		mDestroy = true;
		return;
	}
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

EnemyBall* ABoss::SpawnBall(int addDamage, float speed, float multiplyScale, sf::Vector2f pos, sf::Vector2f direction)
{
	EnemyBall* b = new EnemyBall(mDamage + addDamage, speed, mScaleBall * multiplyScale, direction.x, direction.y);

	b->setPosition(pos);

	GameManager::Get()->GetCurrentScene()->addEntity(b);

	return b;
}
