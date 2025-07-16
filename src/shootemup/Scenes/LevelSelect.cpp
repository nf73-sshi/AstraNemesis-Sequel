#include "LevelSelect.h"
#include "../Important/res.h"

Lvl1Button::Lvl1Button() : Button()
{
	CreateSprite("LvlButton", 0, 0, 120, 120);
}

void Lvl1Button::Update(float delta)
{
	Button::Update(delta); 

	if (Button::IsClicked())
		GameManager::Get()->GetCurrentSceneManager().ChangeScene("Lvl1");

}



void LevelSelect::Init()
{
	const float size = 1.5f;

	Background* pBG = new Background();

	Lvl1Button* pLvl1 = new Lvl1Button();
	pLvl1->setPosition(140, 140);

	BackButton* pBack = new BackButton("Menu");
	pBack->setScale(1.5, 1.5);
	pBack->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT - 100);

	addEntity(pBG);
	addEntity(pLvl1);
	addEntity(pBack);

}

void LevelSelect::Update(float delta)
{
	mousePos = sf::Mouse::getPosition();

	Scene::Update(delta);
}
