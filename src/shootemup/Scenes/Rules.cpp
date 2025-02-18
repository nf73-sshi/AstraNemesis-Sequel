#include "Rules.h"
#include "../Sprites/Background.h"
#include "../Important/GameManager.h"
#include "../Important/res.h"

HowToPlay::HowToPlay()
{
	CreateSprite("res/assets/Rules/Rules.png", 0, 0, 384, 206);
}

void HowToPlay::Update(float delta)
{
	return;
}

void Rules::Init()
{
	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	HowToPlay* pHTP = new HowToPlay();
	pHTP->setOrigin(192, 108);
	pHTP->setScale(5, 5);
	pHTP->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.45);

	BackButton* pBack = new BackButton("Menu");
	pBack->setOrigin(160, 100);
	pBack->setScale(1.25, 1.25);
	pBack->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT - 75);

	addEntity(pBG);
	addEntity(pHTP);
	addEntity(pBack);
}

void Rules::Update(float delta)
{
	mousePos = sf::Mouse::getPosition();
	Scene::Update(delta);
}