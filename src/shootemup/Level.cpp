#include "Level.h"
#include "Player.h"
#include "Background.h"
#include "Ball.h"
#include "Enemy1.h"
#include <iostream>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


void Level::Init()
{
	playerPos.x = 0;
	playerPos.y = 0;
	mCurrentTimer = 0;

	Player* pPlayer = new Player("Ship", 69, 500, 1);
	pPlayer->setOrigin(32, 32);
	pPlayer->scale(1.5, 1.5);
	pPlayer->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);
	mCurrentPlayer = pPlayer;

	Enemy1* pBoss = new Enemy1("Classic mob", 1, 40, 0.5f);
	pBoss->setOrigin(266.5f, 127.5f);
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.15);

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

	if (mCurrentTimer > 0.1) {
		Ball* b = new Ball(1, 2000, 0);

		b->setOrigin(8.5, 8.5);
		b->setPosition(playerPos.x, playerPos.y); 
		addEntity(b);
		mCurrentTimer = 0;
	}

	mCurrentTimer += delta;
	var += delta;
	std::cout << "x = " << playerPos.x << std::endl;
	std::cout << "y = " << playerPos.y << std::endl;
}


void Level::GetPosition(Entity* pPlayer)
{
	playerPos = pPlayer->getPosition();
}

