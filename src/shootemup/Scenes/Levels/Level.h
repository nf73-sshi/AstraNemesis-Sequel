#pragma once
#include "../Scene.h"
#include <SFML/Graphics/Text.hpp>

class Player;

class Level : public Scene
{
protected:
	float mEndTimer;
	Player* pCurrentPlayer;
public:
	virtual void Init();
	void InitUI();
	virtual void Update(float delta);
};

