#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "Entity.h"
#include "Player.h"
#include "Level.h"

GameManager* GameManager::mInstance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager();
	}

	return mInstance;
}

//void GameManager::FullScreen(sf::RenderWindow* window, bool &isFullScreen)
//{
//	if (isFullScreen)
//	{
//		window->create(sf::VideoMode(1920, 1080), "SFML WORK!", sf::Style::Default);
//
//		isFullScreen = false;
//	}
//	else
//	{
//		window->create(sf::VideoMode(1920, 1080), "SFML WORK!", sf::Style::Fullscreen);
//
//		isFullScreen = true;
//	}
//}

void GameManager::RunGame()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Shoot Them Down!", sf::Style::Fullscreen);
	bool isFullScreen = true;

	window.setFramerateLimit(240);

	sf::Clock clock;

	Scene* s1 = new Level();

	s1->Init();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		float delta = clock.restart().asSeconds();

		s1->Update(delta);

		window.clear();
		window.draw(*s1);
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

		
