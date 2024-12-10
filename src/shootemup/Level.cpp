#include "Level.h"
#include "Player.h"
#include "Background.h"
#include "Ball.h"
#include <iostream>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


void Level::Init()
{
	pos.x = 0;
	pos.y = 0;
	mCurrentTimer = 0;

	Player* pPlayer = new Player("Ship", 69, 500, 1);
	pPlayer->setOrigin(32, 32);
	pPlayer->scale(1.5, 1.5);
	pPlayer->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);
	mCurrentPlayer = pPlayer;

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	addEntity(pBG);
	addEntity(pPlayer);
	 
}

void Level::Update(float delta)
{
	GetPosition(mCurrentPlayer);

	Scene::Update(delta);

	if (mCurrentTimer > 0.1) {
		Ball* b = new Ball(1, 2000, 0);

		b->setOrigin(8.5, 8.5);
		b->setPosition(pos.x, pos.y); 
		addEntity(b);
		mCurrentTimer = 0;
	}

	mCurrentTimer += delta;
	var += delta;
	std::cout << "x = " << pos.x << std::endl;
	std::cout << "y = " << pos.y << std::endl;
}


void Level::GetPosition(Entity* pPlayer)
{
	pos = pPlayer->getPosition();
}

