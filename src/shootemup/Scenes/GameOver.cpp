#include "GameOver.h"
#include "../Sprites/Background.h"
#include "../Important/GameManager.h"
#include <iostream>
#include "../Important/AssetManager.h"

#define WINDOW_WIDTH 1920 
#define WINDOW_HEIGHT 1080 


GameOverButton::GameOverButton() : Button()
{
	mDestroy = false;
	CreateSprite("GameOverButton", 0, 0, 350, 256);
}

void GameOverButton::Update(float delta)
{
	Button::Update(delta);

	if (mBoundingBox.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) { 
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{ 
			GameManager().GetInstance()->GetCurrentSceneManager().ChangeScene("Menu"); 
			GameManager().GetInstance()->GetCurrentSceneManager().GetCurrentScene()->Init(); 
			sf::Mouse::setPosition(sf::Vector2i(WINDOW_WIDTH *0.5, WINDOW_HEIGHT * 0.1));
		} 
	} 
}



void GameOver::Init()
{
	mWindow = GameManager::GetInstance()->GetWindow();

	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -WINDOW_HEIGHT);

	GameOverButton* pGO = new GameOverButton();
	pGO->setOrigin(175, 128);
	pGO->setScale(3, 3);
	pGO->setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5);

	addEntity(pBG);
	addEntity(pGO);

	auto am = AssetManager::Get();

	am->StopAllMusics();
	am->GetMusic("Calm Space")->play();
}

void GameOver::Update(float delta)
{
	mousePos = sf::Mouse::getPosition(*mWindow);

	Scene::Update(delta);

	return;
}
