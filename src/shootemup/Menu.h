#pragma once
#include "Scene.h"

class PlayButton : public Entity
{
	sf::Vector2f mPos;
	float mVelocity;
public:
	PlayButton();
	void Update(float delta) override;
};

class ShopButton : public Entity
{
	sf::Vector2f mPos; 
	float mVelocity;
public:
	ShopButton();
	void Update(float delta) override;
};

class QuitButton : public Entity
{
	sf::Vector2f mPos; 
	float mVelocity;
public:
	QuitButton();
	void Update(float delta) override;
};


class Menu : public Scene
{
	sf::Vector2f mousePos;

public:
	void Init();
	void Update(float delta) override; 

};

