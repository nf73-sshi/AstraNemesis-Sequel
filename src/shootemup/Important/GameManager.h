#pragma once
#include "../Scenes/SceneManager.h"
#include "Stats.h"
#include "../Important/AssetManager.h"

class Scene;
class Player;

class GameManager
{

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

public:
	sf::Font mFont;

	static GameManager* GetInstance();

	void Init();

	void Update();

	void Draw();
	
	void RunGame();

	Scene* GetCurrentScene();

	void InitAssets();

	bool GetIsDebugMod();

	SceneManager& GetCurrentSceneManager();

	sf::RenderWindow* GetWindow();

	Stats& GetStats();

	Player* GetCurrentPlayer();
	void SetCurrentPlayer(Player* pCurrentPlayer);
};

