#include "Level.h"
#include "Player.h"
#include "Background.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
void Level::Init()
{
	Player* pPlayer = new Player("Ship", 69, 500, 1);
	pPlayer->setOrigin(32, 32);
	pPlayer->scale(1.5, 1.5);
	pPlayer->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	addEntity(pBG);
	addEntity(pPlayer);
	 
}
