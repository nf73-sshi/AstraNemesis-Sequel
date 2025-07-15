#pragma once
#include "../Scenes/SceneManager.h"
#include "Stats.h"
#include "../Important/AssetManager.h"

class Scene;
class Player;

class GameManager
{
	void InitMusics();
	void InitSFX();
	void InitTextures();

	float dt;

protected:
	static GameManager* mInstance;
	SceneManager mSceneManager;
	Scene* mCurrentScene;
	sf::RenderWindow* mWindow;
	Player* mCurrentPlayer;
	Stats mCurrentStats;

	AssetManager* mAssetManager = AssetManager::Get(); 

	bool debugMod;

	void DebugMod();

	bool play = true;


	float mTimerPause = 0.f;

public:
	sf::Font mFont;
	bool pause = false;

	static GameManager* GetInstance(); 

	void Init();

	void Update();

	void Draw();
	
	void RunGame();

	float GetDeltaTime() { return dt; }

	Scene* GetCurrentScene();

	void InitAssets();

	bool GetIsDebugMod();

	SceneManager& GetCurrentSceneManager();

	sf::RenderWindow* GetWindow();

	Stats& GetStats();

	Player* GetCurrentPlayer();
	void SetCurrentPlayer(Player* pCurrentPlayer);

	void StopGame() { play = false; }

	void SwitchGameState();
};

