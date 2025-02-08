#pragma once
#include "../Scenes/SceneManager.h"
#include "Stats.h"

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

	bool debugMod;

	void DebugMod();

public:
	static GameManager* GetInstance();

	void Init();

	void Update();

	void Draw();
	
	void RunGame();

	Scene* GetCurrentScene();

	bool GetIsDebugMod();

	SceneManager& GetCurrentSceneManager();

	sf::RenderWindow* GetWindow();

	Stats& GetStats();

	Player* GetCurrentPlayer();
	void SetCurrentPlayer(Player* pCurrentPlayer);
};

