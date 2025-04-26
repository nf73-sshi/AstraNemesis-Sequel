#include "Level1.h"
#include "../../Important/res.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/GameManager.h"
#include "../../Bosses/Boss1.h"
#include "../../PlayerMobs/Mob1.h"
#include "../../Important/AssetManager.h"
#include "../../PlayerMobs/Player.h"
#include <iostream>


void Level1::Init()
{
	Level::Init();

	ABoss* pBoss = new Boss1();
	pBoss->setOrigin(266.5f, 127.5f);
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.4, 127.5); 

	HealthBar* pBossHB = new HealthBar(1500.f, 20.f);
	pBoss->SetLifeBar(pBossHB);
	pBossHB->SetBarPosition(50, 10);

	addEntity(pBoss); 
	addEntity(pBossHB);

	InitUI();

	auto am = AssetManager::Get();

	am->StopAllMusics();
	am->GetMusic("Dynamic Music2")->play();
}

void Level1::Update(float delta)
{	
	Level::Update(delta);

	if (Scene::GetAll<ABoss>().size() + Scene::GetAll<Mob1>().size() <= 0 && pCurrentPlayer->Health::IsDead() == false)
	{
		pCurrentPlayer->SetInvincible(true);

		auto jingle = AssetManager::Get()->GetSound("Winning");

		if (mIsWon == false)  
		{
			AssetManager::Get()->StopAllMusics();
			jingle->play(); 
			mIsWon = true;
		}

		if (jingle->getStatus() == sf::Sound::Status::Stopped)
		{
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Menu"); 
		}
	}
}
