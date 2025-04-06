#include "BackButton.h"
#include "../Important/GameManager.h"

BackButton::BackButton(const char* sceneName)
{
	CreateSprite("BackButton", 0, 0, 200, 120);
	mSceneToGo = sceneName; 
}

void BackButton::Update(float delta)
{
	Button::Update(delta);

	if (Button::IsClicked())
		GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene(mSceneToGo);

	return;
}