#include "LevelSelect.h"
#include "../Important/res.h"

Lvl1Button::Lvl1Button() : Button()
{
	CreateSprite("res/assets/LevelSelection/lvl1Button.png", 0, 0, 120, 120);
}

void Lvl1Button::Update(float delta)
{
	Button::Update(delta); 

	if (Button::IsClicked())
		GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Lvl1");

}



void LevelSelect::Init()
{
	const float size = 1.5f;

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	Lvl1Button* pLvl1 = new Lvl1Button();
	pLvl1->setOrigin(60, 60);
	pLvl1->setPosition(140, 140);

	BackButton* pBack = new BackButton("Menu");
	pBack->setOrigin(160, 100);
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
