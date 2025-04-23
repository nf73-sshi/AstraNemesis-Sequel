#include "Level1.h"
#include "../../PlayerMobs/Player.h"
#include "../../Sprites/Background.h"
#include "../../Sprites/UI.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/GameManager.h"
#include "../../HealthMana/ManaBar.h"
#include "../../Bosses/Boss1.h"
#include "../../PlayerMobs/Mob1.h"
#include <iostream>
#include "../../Important/res.h"


void Level1::Init()
{
	Level::Init();

	ABoss* pBoss = new Boss1();
	pBoss->setOrigin(266.5f, 127.5f);
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.4, 127.5);

	HealthBar* pBossHB = new HealthBar();
	pBossHB->GetMHpBarFilled()->setPosition(WINDOW_WIDTH - 250, 30);
	pBossHB->GetMHpBarEmpty()->setPosition(WINDOW_WIDTH - 250, 30);
	pBoss->SetLifeBar(pBossHB);

	addEntity(pBoss); 
	addEntity(pBossHB);
}

void Level1::Update(float delta)
{	
	Level::Update(delta);

	DrawText(&textPlayerHP, "UWUWUWUWU", WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f, 48, sf::Color::White);

	if (Scene::GetAll<ABoss>().size() + Scene::GetAll<Mob1>().size() <= 0)
	{
		mEndTimer -= delta;

		if (mEndTimer <= 0.f)
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Menu");
	}
}
