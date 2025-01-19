#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Rules.h"
#include "Entity.h"
#include "Player.h"
#include "Level1.h"
#include "Menu.h"
#include "LevelSelect.h"
#include "GameOver.h"
#include "res.h"

GameManager* GameManager::mInstance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager();
	}

	return mInstance;
}

void GameManager::Initiate()
{
	mSceneManager.AddScene("Menu", new Menu());
	mSceneManager.AddScene("LevelSelect", new LevelSelect());
	mSceneManager.AddScene("Rules", new Rules());
	mSceneManager.AddScene("GameOver", new GameOver());
	mSceneManager.AddScene("Lvl1", new Level1());
	mSceneManager.ChangeScene("Menu");
	mCurrentScene = mSceneManager.GetCurrentScene();
}

void GameManager::Update()
{
	mCurrentScene = mSceneManager.GetCurrentScene();
}

void GameManager::RunGame()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Astra Nemesis !", sf::Style::Fullscreen);
	bool isFullScreen = true;
	
	mWindow = &window; 

	window.setFramerateLimit(240);

	mCurrentScene = nullptr;

	Initiate(); 

	sf::Clock clock;

	mCurrentScene->Init();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		float delta = clock.restart().asSeconds();


		Update();
		mSceneManager.GetCurrentScene()->Update(delta);

		window.clear();
		window.draw(*mSceneManager.GetCurrentScene());
		window.display();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
		{
			if (!isFullScreen)
			{
				window.create(sf::VideoMode(1920, 1080), "Shoot Them Down !", sf::Style::Fullscreen);
				isFullScreen = true;
			}
		}	

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if (isFullScreen)
			{
				window.create(sf::VideoMode(1920, 1080), "Shoot Them Down !", sf::Style::Close);
				isFullScreen = false;
			}
		}
	}
}

Scene* GameManager::GetCurrentScene()
{
	return mCurrentScene;
}

SceneManager& GameManager::GetCurrentSceneManager()
{
	return mSceneManager;
}

sf::RenderWindow* GameManager::GetWindow()
{
	return mWindow;
}

Player* GameManager::GetCurrentPlayer()
{
	return mCurrentPlayer;
}

void GameManager::SetCurrentPlayer(Player* pCurrentPlayer)
{
	mCurrentPlayer = pCurrentPlayer;
}

		
