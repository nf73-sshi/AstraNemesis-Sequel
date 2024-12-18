#pragma once
#include "Scene.h"
#include <string>

class SceneManager
{

protected:
	std::map<std::string, Scene*> map;
	Scene* mCurrentScene;

public:

	Scene* GetCurrentScene();
	void ChangeScene(std::string id);
	void AddScene(std::string id, Scene* pScene);






};

