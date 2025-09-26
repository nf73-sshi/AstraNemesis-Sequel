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

const float VOL = 1.f;
const int changeWindowDelay = 2;

GameManager* GameManager::mInstance = nullptr;

void GameManager::InitMusics()
{
	mAssetManager->LoadMusic("Calm Space", "res/assets/Musics/calm_space.wav");
	mAssetManager->LoadMusic("Dynamic Music1", "res/assets/Musics/dynamic_music1.wav");
	mAssetManager->LoadMusic("Dynamic Music2", "res/assets/Musics/dynamic_music2.wav");
	mAssetManager->LoadMusic("Menu1", "res/assets/Musics/menu1.wav");

	mAssetManager->GetMusic("Calm Space")->setLoop(true);
	mAssetManager->GetMusic("Calm Space")->setVolume(35 * VOL);

	mAssetManager->GetMusic("Dynamic Music1")->setLoop(true);
	mAssetManager->GetMusic("Dynamic Music1")->setVolume(50 * VOL); 

	mAssetManager->GetMusic("Dynamic Music2")->setLoop(true);
	mAssetManager->GetMusic("Dynamic Music2")->setVolume(55 * VOL); 

	mAssetManager->GetMusic("Menu1")->setLoop(true);
	mAssetManager->GetMusic("Menu1")->setVolume(35 * VOL);
}

void GameManager::InitSFX()
{
	mAssetManager->LoadSound("Beep", "res/assets/SFX/beep.wav");
	mAssetManager->LoadSound("Applause", "res/assets/SFX/applause.wav");
	mAssetManager->LoadSound("Boost1", "res/assets/SFX/boost1.wav");
	mAssetManager->LoadSound("Boost2", "res/assets/SFX/boost2.wav");
	mAssetManager->LoadSound("Die1", "res/assets/SFX/die1.wav");
	mAssetManager->LoadSound("Epic Intro", "res/assets/SFX/epic_intro.wav");
	mAssetManager->LoadSound("Explosion1", "res/assets/SFX/explosion1.wav");
	mAssetManager->LoadSound("Game Over", "res/assets/SFX/game_over.wav");
	mAssetManager->LoadSound("Heal1", "res/assets/SFX/heal1.wav");
	mAssetManager->LoadSound("Heal2", "res/assets/SFX/heal2.wav");
	mAssetManager->LoadSound("Hit1", "res/assets/SFX/hit1.wav");
	mAssetManager->LoadSound("Hit2", "res/assets/SFX/hit2.wav");
	mAssetManager->LoadSound("Laser1", "res/assets/SFX/laser1.wav");
	mAssetManager->LoadSound("Laser2", "res/assets/SFX/laser2.wav");
	mAssetManager->LoadSound("Laser3", "res/assets/SFX/laser3.wav");
	mAssetManager->LoadSound("Winning", "res/assets/SFX/winning_jingle.wav");

	mAssetManager->GetSound("Beep")->setVolume(100 * VOL);
	mAssetManager->GetSound("Applause")->setVolume(100 * VOL);
	mAssetManager->GetSound("Boost1")->setVolume(10 * VOL);
	mAssetManager->GetSound("Boost2")->setVolume(100 * VOL);
	mAssetManager->GetSound("Die1")->setVolume(35 * VOL);
	mAssetManager->GetSound("Epic Intro")->setVolume(100 * VOL);
	mAssetManager->GetSound("Explosion1")->setVolume(75 * VOL);
	mAssetManager->GetSound("Game Over")->setVolume(100 * VOL);
	mAssetManager->GetSound("Heal1")->setVolume(80 * VOL);
	mAssetManager->GetSound("Heal2")->setVolume(100 * VOL);
	mAssetManager->GetSound("Hit1")->setVolume(100 * VOL);
	mAssetManager->GetSound("Hit2")->setVolume(50 * VOL);
	mAssetManager->GetSound("Laser1")->setVolume(45 * VOL);
	mAssetManager->GetSound("Laser2")->setVolume(45 * VOL);
	mAssetManager->GetSound("Laser3")->setVolume(45 * VOL);
	mAssetManager->GetSound("Winning")->setVolume(50 * VOL); 
}

void GameManager::InitTextures()
{
	//Gameplay Assets
	mAssetManager->LoadTexture("BulletsTile", "res/assets/Images/bulletsTile.png");
	mAssetManager->LoadTexture("MobsTile", "res/assets/Images/mobs.png");
	mAssetManager->LoadTexture("Player", "res/assets/Images/vaisseau.png");
	mAssetManager->LoadTexture("Boss1", "res/assets/Images/Boss1.png");

	//Levels
	mAssetManager->LoadTexture("lvl1Button", "res/assets/LevelSelection/lvl1Button_v2.png");
	mAssetManager->LoadTexture("lvl2Button", "res/assets/LevelSelection/lvl2Button.png");

	//Buttons
	mAssetManager->LoadTexture("GameOverButton", "res/assets/Menu/gameover.png");
	mAssetManager->LoadTexture("BackButton", "res/assets/Rules/backButton.png");
	mAssetManager->LoadTexture("ShopButton", "res/assets/Menu/shopButton.png");
	mAssetManager->LoadTexture("PlayButton", "res/assets/Menu/playButton.png");
	mAssetManager->LoadTexture("RulesButton", "res/assets/Menu/rulesButton.png");
	mAssetManager->LoadTexture("QuitButton", "res/assets/Menu/quitButton.png");

	//Others
	mAssetManager->LoadTexture("Rules", "res/assets/Rules/Rules.png");
	mAssetManager->LoadTexture("BackgroundSpace", "res/assets/Images/spaceHeavyLess.png");
	mAssetManager->LoadTexture("Title", "res/assets/Menu/title.png");
	mAssetManager->LoadTexture("BackButton", "res/assets/Rules/backButton.png");

	//UI
	mAssetManager->LoadTexture("UI", "res/assets/Interface/UI.png");
	mAssetManager->LoadTexture("SkillHeal", "res/assets/Interface/skillHeal.png");
	mAssetManager->LoadTexture("SkillBallX2", "res/assets/Interface/skillBallX2.png");
}

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

GameManager* GameManager::Get()
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

	// ALL SCENES
	mSceneManager.AddScene("Menu", new Menu()); 
	mSceneManager.AddScene("LevelSelect", new LevelSelect());
	mSceneManager.AddScene("Rules", new Rules());
	mSceneManager.AddScene("GameOver", new GameOver());
	mSceneManager.AddScene("Lvl1", new Level1());
	mSceneManager.ChangeScene("Menu");
	//

	mCurrentScene = mSceneManager.GetCurrentScene();
}

void GameManager::Update()
{
	mCurrentScene = mSceneManager.GetCurrentScene();
}

void GameManager::RunGame()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Astra Nemesis !", sf::Style::Default);
	bool isFullScreen = false;

	InitAssets();

	mWindow = &window;

	window.setFramerateLimit(240);

	mCurrentScene = nullptr;

	Init();

	sf::Clock clock;

	float windowResizeTimer = 0;

	while (window.isOpen() && play == true)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		dt = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
			SwitchGameState();
		else
			if (mTimerPause >= 0)
				mTimerPause -= dt;

		if (pause == true)
			continue;

		Update();
		mSceneManager.GetCurrentScene()->Update(dt);

		window.clear();
		window.draw(*mSceneManager.GetCurrentScene());
		window.display();

		if (windowResizeTimer <= 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11))
			{
				if (!isFullScreen)
				{
					window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Astra Nemesis !", sf::Style::Fullscreen);
					isFullScreen = true;

				}

				windowResizeTimer = changeWindowDelay;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				if (isFullScreen)
				{
					window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Astra Nemesis !", sf::Style::Close);
					isFullScreen = false;

				}

				windowResizeTimer = changeWindowDelay;
			}
		}
		else
			windowResizeTimer -= dt;

		DebugMod();
	}

	delete mAssetManager;
}

Scene* GameManager::GetCurrentScene()
{
	return mCurrentScene;
}

void GameManager::InitAssets()
{
	InitTextures();
	InitSFX();
	InitMusics();
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

void GameManager::SwitchGameState()
{
	if (mTimerPause <= 0.f)
	{
		pause = !pause;
		mAssetManager->GetSound("Beep")->play();
		mTimerPause = 0.5f;
		AssetManager::Get()->PauseOrDePauseAll();
	}
}


