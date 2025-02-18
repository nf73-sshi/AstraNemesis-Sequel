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
	pHTP->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);

	BackButton* pBack = new BackButton("Menu");
	pBack->setOrigin(160, 100);
	pBack->setScale(1.5, 1.5);
	pBack->setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 200);

	addEntity(pBG);
	addEntity(pHTP);
	addEntity(pBack);
}

void Rules::Update(float delta)
{
	mousePos = sf::Mouse::getPosition();
	Scene::Update(delta);
}