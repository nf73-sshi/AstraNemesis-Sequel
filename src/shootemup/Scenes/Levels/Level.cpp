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
	mEndTimer = 3.f;

	pCurrentPlayer = new Player();

	GameManager::GetInstance()->SetCurrentPlayer(pCurrentPlayer);

	pCurrentPlayer->setOrigin(32, 32);
	pCurrentPlayer->scale(1.5, 1.5);
	pCurrentPlayer->setPosition(WINDOW_WIDTH * 0.4, WINDOW_HEIGHT * 0.7);

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	addEntity(pBG);
	addEntity(pCurrentPlayer);
}

void Level::InitUI()
{
	UI* pUI = new UI();
	pUI->setOrigin(75, 270);
	pUI->setScale(2, 2);
	pUI->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT * 0.5);
	addEntity(pUI);

	HealthBar* pPlayerHB = new HealthBar(200.f, 30.f);
	pCurrentPlayer->SetLifeBar(pPlayerHB);
	pPlayerHB->SetBarPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);

	ManaBar* pManaB = new ManaBar();

	pManaB->GetManaBarFilled()->setPosition(WINDOW_WIDTH - 275, WINDOW_HEIGHT - 120);
	pManaB->GetManaBarEmpty()->setPosition(WINDOW_WIDTH - 275, WINDOW_HEIGHT - 120);
	pCurrentPlayer->SetManaBar(pManaB);

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
