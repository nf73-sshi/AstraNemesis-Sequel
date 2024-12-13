#include "SceneManager.h"


Scene* SceneManager::GetCurrentScene()
{
	return mCurrentScene;
}

void SceneManager::ChangeScene(std::string id)
{
	mCurrentScene = map[id];
}

void SceneManager::AddScene(std::string id, Scene* pScene)
{
	map[id] = pScene;
}


