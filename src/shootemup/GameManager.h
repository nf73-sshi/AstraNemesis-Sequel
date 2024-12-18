#pragma once

class Scene;
#include "SceneManager.h"

class GameManager
{

protected:
	static GameManager* mInstance;
	SceneManager mSceneManager;
	Scene* mCurrentScene;
	sf::RenderWindow* mWindow;

public:
	static GameManager* GetInstance();

	void Initiate();

	void Update();

	void Draw();
	
	void RunGame();

	Scene* GetCurrentScene();

	SceneManager& GetCurrentSceneManager();

	sf::RenderWindow* GetWindow();
};

