#pragma once
#include "Scene.h"
#include "../Buttons/Button.h"
#include "../Sprites/Title.h"

class PlayButton : public Button
{

public:
	PlayButton();
	void Update(float delta) override;
};

class ShopButton : public Button
{

public:
	ShopButton(); 
	void Update(float delta) override;
};

class RulesButton : public Button
{

public:
	RulesButton();
	void Update(float delta) override;

};

class QuitButton : public Button
{

public:
	QuitButton();
	void Update(float delta) override;
};


class Menu : public Scene
{

public:
	void Init();
	void Update(float delta) override; 

};

