#include "Menu.h"
#include "Background.h"
#include "GameManager.h"
#include <iostream>

#define WINDOW_WIDTH 1920 
#define WINDOW_HEIGHT 1080 

float mTimer = 0;
const int min = 100;
const int rdm = 567;

PlayButton::PlayButton()
{
	CreateSprite("../../../res/assets/Menu/playButton.png", 0, 0, 200, 120);
}

void PlayButton::Update(float delta)
{
	Button::Update(delta);

	if (mBoundingBox.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			GameManager().GetInstance()->GetCurrentSceneManager().ChangeScene("Lvl1"); 
			GameManager().GetInstance()->GetCurrentSceneManager().GetCurrentScene()->Init();
		}
	}

	if (mPos.x < 150) 
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = - (min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}



ShopButton::ShopButton()
{
	CreateSprite("../../../res/assets/Menu/shopButton.png", 0, 0, 200, 120);
}

void ShopButton::Update(float delta)
{
	Button::Update(delta);

	if (mTimer < 1)
		return;


	if (mPos.x < 150)
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = - (min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}



QuitButton::QuitButton()
{
	CreateSprite("../../../res/assets/Menu/quitButton.png", 0, 0, 200, 120);
}

void QuitButton::Update(float delta)
{
	Button::Update(delta);

	if (mBoundingBox.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			exit(69);
		}
	}

	if (mTimer < 2)
		return;

	if (mPos.x < 150)
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = -(min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}



void Menu::Init()
{
	mWindow = GameManager::GetInstance()->GetWindow();

	const float size = 1.5f;

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -WINDOW_HEIGHT);

	PlayButton* pPlay = new PlayButton();
	pPlay->setOrigin(100, 60);
	pPlay->setScale(size, size); 
	pPlay->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);

	ShopButton* pShop = new ShopButton();
	pShop->setOrigin(100, 60);
	pShop->setScale(size,size); 
	pShop->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.7);

	QuitButton* pQuit = new QuitButton();
	pQuit->setOrigin(100, 60);
	pQuit->setScale(size, size);
	pQuit->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.9);

	Title* pTitle = new Title();
	pTitle->setOrigin(171, 100);
	pTitle->setScale(2.3, 2); 
	pTitle->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.2); 

	addEntity(pBG);
	addEntity(pPlay);
	addEntity(pShop);
	addEntity(pQuit);
	addEntity(pTitle); 

}


void Menu::Update(float delta)
{
	mousePos = sf::Mouse::getPosition(*mWindow); 

	mTimer += delta;
	Scene::Update(delta);
}

