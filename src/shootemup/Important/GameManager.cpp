#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "res.h"
#include "GameManager.h"
#include "../Scenes/SceneManager.h"
#include "../Scenes/Scene.h"
#include "../Scenes/Rules.h"
#include "../Others/Entity.h"
#include "../PlayerMobs/Player.h"
#include "../Scenes/Levels/Level1.h"
#include "../Scenes/Menu.h"
#include "../Scenes/LevelSelect.h"
#include "../Scenes/GameOver.h"
#include "../Important/res.h"

GameManager* GameManager::mInstance = nullptr;

void GameManager::DebugMod()
{
	if (debugMod == true)
		return;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				std::cout << "Debug Mod Activated !\n";
				debugMod = true;
			}
		}
	}
}

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager();
	}

	return mInstance;
}

void GameManager::Init()
{
	if (mFont.loadFromFile("res/vhs-gothic.ttf") )
	{
		std::cout << "Path 1 : Font loaded !\n";
	}
	else
	{
		if (mFont.loadFromFile("../../../res/vhs-gothic.ttf"))
		{
			std::cout << "Path 2 : Font Loaded !\n";
		}
	}

	debugMod = false;

	std::fstream Data("../../../res/const_data.txt");

	std::string myText;
	std::getline(Data, myText);

	std::cout << myText << std::endl;

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

	InitAssets();

	mWindow = &window;

	window.setFramerateLimit(240);

	mCurrentScene = nullptr;

	Init();

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

		DebugMod();

	}
}

Scene* GameManager::GetCurrentScene()
{
	return mCurrentScene;
}

void GameManager::InitAssets()
{
	mAssetManager->LoadTexture("BulletsTile", "res/assets/Images/bulletsTile.png");
	mAssetManager->LoadTexture("BackButton", "res/assets/Rules/backButton.png");
	mAssetManager->LoadTexture("MobsTile", "res/assets/Images/mobs.png");
	mAssetManager->LoadTexture("Player", "res/assets/Images/vaisseau.png");
	mAssetManager->LoadTexture("Boss1", "res/assets/Images/Boss1.png");
	mAssetManager->LoadTexture("GameOverButton", "res/assets/Menu/gameover.png");
	mAssetManager->LoadTexture("LvlButton", "res/assets/LevelSelection/lvl1Button.png");

	mAssetManager->LoadTexture("ShopButton", "res/assets/Menu/shopButton.png");
	mAssetManager->LoadTexture("PlayButton", "res/assets/Menu/playButton.png");
	mAssetManager->LoadTexture("RulesButton", "res/assets/Menu/rulesButton.png");
	mAssetManager->LoadTexture("QuitButton", "res/assets/Menu/quitButton.png");
	mAssetManager->LoadTexture("Rules", "res/assets/Rules/Rules.png");
	mAssetManager->LoadTexture("BackgroundSpace", "res/assets/Images/spaceHeavyLess.png");

	mAssetManager->LoadTexture("Title", "res/assets/Menu/title.png");
	mAssetManager->LoadTexture("BackButton", "res/assets/Rules/backButton.png");
	mAssetManager->LoadTexture("UI", "res/assets/Interface/UI.png");
}

bool GameManager::GetIsDebugMod()
{
	return debugMod;
}

SceneManager& GameManager::GetCurrentSceneManager()
{
	return mSceneManager;
}

sf::RenderWindow* GameManager::GetWindow()
{
	return mWindow;
}

Stats& GameManager::GetStats()
{
	return mCurrentStats;
}

Player* GameManager::GetCurrentPlayer()
{
	return mCurrentPlayer;
}

void GameManager::SetCurrentPlayer(Player* pCurrentPlayer)
{
	mCurrentPlayer = pCurrentPlayer;
}


