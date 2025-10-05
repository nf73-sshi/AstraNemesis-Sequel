#include "Level1.h"
#include <iostream>
#include "../../Important/res.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/AssetManager.h"
#include "../../Bosses/Boss1.h"
#include "../../PlayerMobs/Mob.h"


void Level1::Init()
{
	Level::Init();

	auto am = AssetManager::Get();

	am->PlayMusic("Dynamic Music2");

	ABoss* pBoss = new Boss1();
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.4, 127.5); 

	HealthBar* pBossHB = new HealthBar(1500.f, 20.f);
	pBoss->SetLifeBar(pBossHB);
	pBossHB->SetBarPosition(50, 10);

	addEntity(pBoss); 
	addEntity(pBossHB);
}
