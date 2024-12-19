#pragma once
#include "Scene.h"
#include "Button.h"

class HowToPlay : public Entity
{

public:
	HowToPlay();
	void Update(float delta) override;
};

class BackButton : public Button
{

public:
	BackButton();
	void Update(float delta) override;
};

class Rules : public Scene
{

public:
	void Init();
	void Update(float delta) override;
};