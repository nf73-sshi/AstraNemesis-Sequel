#pragma once
#include "Scene.h"
#include <string>
#include <unordered_map>

class SceneManager
{

protected:
	std::unordered_map<std::string, Scene*> map;
	Scene* mCurrentScene;

public:

	Scene* GetCurrentScene();
	void ChangeScene(std::string id);
	void AddScene(std::string id, Scene* pScene);

};

