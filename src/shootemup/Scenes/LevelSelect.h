#pragma once
#include "Scene.h"
#include "../Sprites/Background.h"
#include "../Important/GameManager.h"
#include "../Buttons/Button.h"
#include "../Buttons/BackButton.h"

class Lvl1Button : public Button
{

public:
	Lvl1Button();
	void Update(float delta) override;
};


class LevelSelect : public Scene
{

public:
	void Init();
	void Update(float delta) override;

};

