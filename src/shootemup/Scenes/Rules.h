#pragma once
#include "Scene.h"
#include "../Buttons/Button.h"
#include "../Buttons/BackButton.h"

class HowToPlay : public Entity
{

public:
	HowToPlay();
	void Update(float delta) override;
};

class Rules : public Scene
{

public:
	void Init();
	void Update(float delta) override;
};