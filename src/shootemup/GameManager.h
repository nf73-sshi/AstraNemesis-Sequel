#pragma once
#include "SceneManager.h"
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

public:
	static GameManager* GetInstance();

	void Initiate();

	void Update();

	void Draw();
	
	void RunGame();

	Scene* GetCurrentScene();

	SceneManager& GetCurrentSceneManager();

	sf::RenderWindow* GetWindow();

	Stats& GetStats();

	Player* GetCurrentPlayer();
	void SetCurrentPlayer(Player* pCurrentPlayer);
};

