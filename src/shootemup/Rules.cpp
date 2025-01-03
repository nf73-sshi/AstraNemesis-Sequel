#include "Rules.h"
#include "Background.h"
#include "GameManager.h"

#define WINDOW_WIDTH 1920 
#define WINDOW_HEIGHT 1080 

HowToPlay::HowToPlay()
{
	CreateSprite("../../../res/assets/Rules/Rules.png", 0, 0, 384, 206);
}

void HowToPlay::Update(float delta)
{
	return;
}

BackButton::BackButton()
{
	CreateSprite("../../../res/assets/Rules/backButton.png", 0, 0, 200, 120);
}

void BackButton::Update(float delta)
{
	Button::Update(delta);

	if (mBoundingBox.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Menu");
		}
	}
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

	BackButton* pBack = new BackButton();
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