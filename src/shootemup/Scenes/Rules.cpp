#include "Rules.h"
#include "../Sprites/Background.h"
#include "../Important/GameManager.h"
#include "../Important/res.h"

HowToPlay::HowToPlay()
{
	mDrawPriority = 9;

	CreateSprite("Rules", 0, 0, 384, 206);
}

void HowToPlay::Update(float delta)
{
	return;
}

void Rules::Init()
{
	Background* pBG = new Background();

	HowToPlay* pHTP = new HowToPlay();
	pHTP->setScale(5, 5);
	pHTP->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.45);

	BackButton* pBack = new BackButton("Menu");
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