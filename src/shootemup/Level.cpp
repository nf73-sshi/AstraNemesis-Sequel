#include "Level.h"
#include "Player.h"

void Level::Init()
{
	Player* pPlayer = new Player("Ship", 69, 420, 1);
	pPlayer->setOrigin(32, 32); 
	pPlayer->setPosition(1000, 500);


	addEntity(pPlayer);
	 
}
