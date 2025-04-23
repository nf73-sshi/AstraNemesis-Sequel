#include "Level.h"
#include <iostream>
#include "../../Important/res.h"
#include "../../PlayerMobs/Player.h"
#include "../../Sprites/Background.h"
#include "../../Sprites/UI.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/GameManager.h"
#include "../../HealthMana/ManaBar.h"

void Level::Init()
{
	mEndTimer = 2.f;

	Player* pPlayer = new Player();

	GameManager::GetInstance()->SetCurrentPlayer(pPlayer);

	pPlayer->setOrigin(32, 32);
	pPlayer->scale(1.5, 1.5);
	pPlayer->setPosition(WINDOW_WIDTH * 0.4, WINDOW_HEIGHT * 0.7);

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	UI* pUI = new UI();
	pUI->setOrigin(75, 270);
	pUI->setScale(2, 2);
	pUI->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT * 0.5);

	HealthBar* pPlayerHB = new HealthBar();
	pPlayerHB->GetMHpBarFilled()->setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);
	pPlayerHB->GetMHpBarEmpty()->setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);
	pPlayer->SetLifeBar(pPlayerHB);

	ManaBar* pManaB = new ManaBar();
	pManaB->GetManaBarFilled()->setPosition(WINDOW_WIDTH - 275, WINDOW_HEIGHT - 120);
	pManaB->GetManaBarEmpty()->setPosition(WINDOW_WIDTH - 275, WINDOW_HEIGHT - 120);
	pPlayer->SetManaBar(pManaB);

	addEntity(pBG);

	addEntity(pPlayer);
	addEntity(pUI);

	addEntity(pPlayerHB);
	addEntity(pManaB);
}

void Level::Update(float delta)
{
	Scene::Update(delta);

	if (Scene::GetAll<Player>().size() <= 0)
	{
		mEndTimer -= delta;

		if (mEndTimer <= 0)
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("GameOver");
	}
}
