#include "BackButton.h"
#include "GameManager.h"

BackButton::BackButton(const char* sceneName)
{
	CreateSprite("../../../res/assets/Rules/backButton.png", 0, 0, 200, 120);
	mSceneToGo = sceneName; 
}

void BackButton::Update(float delta)
{
	Button::Update(delta);

	if (mBoundingBox.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene(mSceneToGo);
		}
	}
	return;
}