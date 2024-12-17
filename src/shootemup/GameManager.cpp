#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"
#include "Player.h"
#include "Level.h"
#include "Menu.h"

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
	mSceneManager.AddScene("Lvl1", new Level());
	mSceneManager.ChangeScene("Menu");
	mCurrentScene = mSceneManager.GetCurrentScene();
}

void GameManager::Update()
{
	mCurrentScene = mSceneManager.GetCurrentScene();


}

void GameManager::RunGame()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Shoot Them Down!", sf::Style::Fullscreen);
	bool isFullScreen = true;

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
		mCurrentScene->Update(delta);

		window.clear();
		window.draw(*mCurrentScene);
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
				window.create(sf::VideoMode(1920, 1080), "Shoot Them Down", sf::Style::Default);

				isFullScreen = false;
			}
		}
	}
}

Scene* GameManager::GetCurrentScene()
{
	return mCurrentScene;
}

		
