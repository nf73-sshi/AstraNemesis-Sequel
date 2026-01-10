#include "Level2.h"
#include "../../Important/res.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/AssetManager.h"
#include "../../Important/Debug.h"
#include "../../Bosses/Boss2.h"

void Level2::Init()
{
	Level::Init();

	infinite = true;

	auto am = AssetManager::Get();
	am->PlayMusic("Dynamic Music1");

	ABoss* pBoss = new Boss2();
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.4, 127.5);
	pBoss->SetDefaultPosition(pBoss->getPosition());

	HealthBar* pBossHB = new HealthBar(1500.f, 20.f);
	pBoss->SetLifeBar(pBossHB);
	pBossHB->SetBarPosition(50, 10);

	addEntity(pBoss);
	addEntity(pBossHB);
}