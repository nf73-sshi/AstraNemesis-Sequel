#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "Entity.h"
#include "Player.h"
#include "Level.h"

const int delta = 100;

GameManager* GameManager::mInstance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager();
	}

	return mInstance;
}

void GameManager::RunGame()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Shoot Them Down!");

    sf::Clock clock;

    Scene* s = new Level();

    s->Init();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float delta = clock.restart().asSeconds();

        s->Update(delta); 

        window.clear();
        window.draw(*s);
        window.display();
    }

}