#include "Menu.h"
#include "../Sprites/Background.h"
#include "../Important/GameManager.h"
#include <iostream>
#include "../Important/AssetManager.h"
#include "../Important/res.h"

float mTimer = 0;

PlayButton::PlayButton() : Button() 
{
	CreateSprite("PlayButton", 0, 0, 200, 120);
}

void PlayButton::Update(float delta)
{
	Button::Update(delta);

	if (Button::IsClicked())
		GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("LevelSelect");

	if (mPos.x < 150)
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = -(min + rand() % rdm);
	
	this->move(mVelocity * delta, 0);


	return;
}



ShopButton::ShopButton() : Button()
{
	CreateSprite("ShopButton", 0, 0, 200, 120);
}

void ShopButton::Update(float delta)
{
	Button::Update(delta);

	sprite.setColor(sf::Color(255, 0, 0, 128));

	if (mTimer < 1)
		return;


	if (mPos.x < 150)
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = - (min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}


RulesButton::RulesButton()
{
	CreateSprite("RulesButton", 0, 0, 200, 120);
}

void RulesButton::Update(float delta)
{
	Button::Update(delta);

	if (Button::IsClicked())
		GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Rules");

	if (mTimer < 1)
		return;


	if (mPos.x < 150)
		mVelocity = min + rand() % rdm;

	if (mPos.x > 1770)
		mVelocity = -(min + rand() % rdm);

	this->move(mVelocity * delta, 0);

	return;
}


QuitButton::QuitButton() : Button() 
{
	CreateSprite("QuitButton", 0, 0, 200, 120);
}

void QuitButton::Update(float delta)
{
	Button::Update(delta);

	if (Button::IsClicked())
	{
		GameManager::GetInstance()->StopGame();
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
	const float size = 1.5f;

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	PlayButton* pPlay = new PlayButton();
	pPlay->setOrigin(100, 60);
	pPlay->setScale(size, size); 
	pPlay->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);

	RulesButton* pRules = new RulesButton();
	pRules->setOrigin(100, 60);
	pRules->setScale(size,size); 
	pRules->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.7);

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
	addEntity(pRules);
	addEntity(pQuit);
	addEntity(pTitle);


	AssetManager::Get()->ResetPitchAllMusic();

	auto menuMusic = AssetManager::Get()->GetMusic("Menu1"); 
	if (menuMusic->getStatus() == sf::Sound::Stopped)
	{
		AssetManager::Get()->StopAllMusics(); 
		menuMusic->play(); 
	}

	/////////////////////////////// SUPPRIMER §§§§§§§!
	DrawText("TJAJTATJT", WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f, 40, sf::Color::Red);
}


void Menu::Update(float delta)
{
	mousePos = sf::Mouse::getPosition(); 

	mTimer += delta;

	Scene::Update(delta);
}

