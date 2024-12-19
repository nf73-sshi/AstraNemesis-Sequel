#include "Level1.h"
#include "Player.h"
#include "Background.h"
#include "AllyBall.h"
#include "Boss1.h"
#include <iostream>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


void Level1::Init()
{
	playerPos.x = 0;
	playerPos.y = 0;
	mCurrentTimer = 0;

	Player* pPlayer = new Player();
	pPlayer->setOrigin(32, 32);
	pPlayer->scale(1.5, 1.5);
	pPlayer->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);
	mCurrentPlayer = pPlayer;

	Boss1* pBoss = new Boss1();
	pBoss->setOrigin(266.5f, 127.5f);
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.5, 127.5);

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

<<<<<<< Updated upstream
	addEntity(pBG);
	addEntity(pPlayer);
	addEntity(pBoss); 
=======
	UI* pUI = new UI();
	pUI->setOrigin(75, 270);
	pUI->setScale(2, 2);
	pUI->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT * 0.5);

	HealthBar* pPlayerHB = new HealthBar();
	pPlayerHB->GetMHpBarFilled()->setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);
	pPlayerHB->GetMHpBarEmpty()->setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);

	HealthBar* pBossHB = new HealthBar();
	pBossHB->GetMHpBarFilled()->setPosition(WINDOW_WIDTH - 250, 30);
	pBossHB->GetMHpBarEmpty()->setPosition(WINDOW_WIDTH - 250, 30);


	addEntity(pBG);


	addEntity(pPlayer);
	addEntity(pBoss); 
	addEntity(pUI);

	addEntity(pPlayerHB); 
	addEntity(pBossHB);
>>>>>>> Stashed changes
}

void Level1::Update(float delta)
{
	
	GetPosition(mCurrentPlayer);

	Scene::Update(delta);

	mCurrentTimer += delta;
	var += delta;
}


void Level1::GetPosition(Entity* pPlayer)
{
	playerPos = pPlayer->getPosition(); 
}

