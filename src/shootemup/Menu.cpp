#include "Menu.h"
#include "Background.h"

void Menu::Init()
{
	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(1920 * 0.5, -1080);
	addEntity(pBG);
}


void Menu::Update(float delta)
{
	Scene::Update(delta);
}
