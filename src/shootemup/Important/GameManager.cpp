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
#include "Debug.h"

#include "../Scenes/Levels/Level1.h"
#include "../Scenes/Levels/Level2.h"
#include "../Scenes/Menu.h"
#include "../Scenes/LevelSelect.h"
#include "../Scenes/GameOver.h"
#include "../Important/res.h"

const float VOL = 1.f; // Intensity of volume
const int changeWindowDelay = 2;

GameManager* GameManager::mInstance = nullptr;

void GameManager::InitMusics()
{
	mAssetManager->InitMusic("Calm Space", "res/assets/Musics/calm_space.wav", 35 * VOL);
	mAssetManager->InitMusic("Dynamic Music1", "res/assets/Musics/dynamic_music1.wav", 50 * VOL);
	mAssetManager->InitMusic("Dynamic Music2", "res/assets/Musics/dynamic_music2.wav", 55 * VOL);
	mAssetManager->InitMusic("Menu1", "res/assets/Musics/menu1.wav", 35 * VOL);
}

void GameManager::InitSFX()
{
	mAssetManager->InitSound("Beep", "res/assets/SFX/beep.wav", 100 * VOL);
	mAssetManager->InitSound("Applause", "res/assets/SFX/applause.wav", 100 * VOL);
	mAssetManager->InitSound("Boost1", "res/assets/SFX/boost1.wav", 10 * VOL);
	mAssetManager->InitSound("Boost2", "res/assets/SFX/boost2.wav", 100 * VOL);
	mAssetManager->InitSound("Die1", "res/assets/SFX/die1.wav", 35 * VOL);
	mAssetManager->InitSound("Epic Intro", "res/assets/SFX/epic_intro.wav", 100 * VOL);
	mAssetManager->InitSound("Explosion1", "res/assets/SFX/explosion1.wav", 75 * VOL);
	mAssetManager->InitSound("Game Over", "res/assets/SFX/game_over.wav", 100 * VOL);
	mAssetManager->InitSound("Heal1", "res/assets/SFX/heal1.wav", 80 * VOL);
	mAssetManager->InitSound("Heal2", "res/assets/SFX/heal2.wav", 100 * VOL);
	mAssetManager->InitSound("Hit1", "res/assets/SFX/hit1.wav", 100 * VOL);
	mAssetManager->InitSound("Hit2", "res/assets/SFX/hit2.wav", 50 * VOL);
	mAssetManager->InitSound("Laser1", "res/assets/SFX/laser1.wav", 45 * VOL);
	mAssetManager->InitSound("Laser2", "res/assets/SFX/laser2.wav", 45 * VOL);
	mAssetManager->InitSound("Laser3", "res/assets/SFX/laser3.wav", 45 * VOL);
	mAssetManager->InitSound("Winning", "res/assets/SFX/winning_jingle.wav", 50 * VOL);
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
	{
		Debug::DrawText("Debug mode", 10, WINDOW_HEIGHT - 10, 18, sf::Color::White, 0, 1);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					std::cout << "Debug Mod Desactived !\n";
					debugMod = false;
				}
			}
		}
	}
	else
	{
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

	std::fstream Data("../../../res/const_data.txt");

	std::string myText;
	std::getline(Data, myText);
	std::cout << myText << std::endl;

	InitScenes();
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

		mCurrentScene->Update(dt);

		window.clear();
		window.draw(*mCurrentScene);
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

void GameManager::InitScenes()
{
	mSceneManager.AddScene("Menu", new Menu());
	mSceneManager.AddScene("LevelSelect", new LevelSelect());
	mSceneManager.AddScene("Rules", new Rules());
	mSceneManager.AddScene("GameOver", new GameOver());
	mSceneManager.AddScene("Lvl1", new Level1());
	mSceneManager.AddScene("Lvl2", new Level2());
	mSceneManager.ChangeScene("Menu");
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


