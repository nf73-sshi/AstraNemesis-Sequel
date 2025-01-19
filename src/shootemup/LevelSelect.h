#pragma once
#include "Scene.h"
#include "Background.h"
#include "GameManager.h"
#include "Button.h"
#include "BackButton.h"

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

