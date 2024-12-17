#include "Menu.h"
#include "Background.h"
#define WINDOW_WIDTH 1920 
#define WINDOW_HEIGHT 1080 

float mTimer = 0;
const int min = 100;
const int rdm = 567;

PlayButton::PlayButton()
{
	mVelocity = min;
	CreateSprite("../../../res/assets/Images/playButton.png", 0, 0, 200, 120);
}

void PlayButton::Update(float delta)
{
	mPos = getPosition();

	if (mPos.x < 150) 
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = - (min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}



ShopButton::ShopButton()
{
	mVelocity = min;
	CreateSprite("../../../res/assets/Images/shopButton.png", 0, 0, 200, 120);
}

void ShopButton::Update(float delta)
{
	if (mTimer < 1)
		return;

	mPos = getPosition();

	if (mPos.x < 150)
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = - (min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}



QuitButton::QuitButton()
{
	mVelocity = min;
	CreateSprite("../../../res/assets/Images/quitButton.png", 0, 0, 200, 120);
}

void QuitButton::Update(float delta)
{
	if (mTimer < 2)
		return;

	mPos = getPosition();

	if (mPos.x < 150)
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = -(min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}



void Menu::Init()
{
	const float size = 1.5f;

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -WINDOW_HEIGHT);

	PlayButton* pPlay = new PlayButton();
	pPlay->setOrigin(100, 60);
	pPlay->setScale(size, size); 
	pPlay->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.4);

	ShopButton* pShop = new ShopButton();
	pShop->setOrigin(100, 60);
	pShop->setScale(size,size); 
	pShop->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.6);

	QuitButton* pQuit = new QuitButton();
	pQuit->setOrigin(100, 60);
	pQuit->setScale(size, size);
	pQuit->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.8);

	addEntity(pBG);
	addEntity(pPlay);
	addEntity(pShop);
	addEntity(pQuit);

}


void Menu::Update(float delta)
{
	mTimer += delta;
	Scene::Update(delta);
}


