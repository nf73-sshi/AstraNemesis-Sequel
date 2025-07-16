#include "Level1.h"
#include "../../Important/res.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Bosses/Boss1.h"
#include "../../PlayerMobs/Mob.h"
#include "../../Important/AssetManager.h"
#include <iostream>


void Level1::Init()
{
	Level::Init();

	ABoss* pBoss = new Boss1();
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
