#include "Level.h"
#include "Player.h"
#include "Background.h"
#include "AllyBall.h"
#include "Boss1.h"
#include <iostream>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


void Level::Init()
{
	playerPos.x = 0;
	playerPos.y = 0;
	mCurrentTimer = 0;

	Player* pPlayer = new Player("Ship", 3, 69, 750, 0.25);
	pPlayer->setOrigin(32, 32);
	pPlayer->scale(1.5, 1.5);
	pPlayer->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);
	mCurrentPlayer = pPlayer;

	Boss1* pBoss = new Boss1("Boss 1", 1000, 1, 500, 0.25);
	pBoss->setOrigin(266.5f, 127.5f);
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.5, 127.5);

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	addEntity(pBG);
	addEntity(pPlayer);
	addEntity(pBoss); 
	 
}

void Level::Update(float delta)
{
	GetPosition(mCurrentPlayer);

	Scene::Update(delta);

	mCurrentTimer += delta;
	var += delta;
}


void Level::GetPosition(Entity* pPlayer)
{
	playerPos = pPlayer->getPosition(); 
}

