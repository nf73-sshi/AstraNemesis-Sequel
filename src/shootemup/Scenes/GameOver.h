#pragma once
#include "Scene.h"
#include "../Others/Entity.h"
#include "../Buttons/Button.h"

class GameOverButton : public Button
{

public:
	GameOverButton();
	void Update(float delta) override;

};

class GameOver : public Scene
{

public:
	void Init();
	void Update(float delta) override;
};

