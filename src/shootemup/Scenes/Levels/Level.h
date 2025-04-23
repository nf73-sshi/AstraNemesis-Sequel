#pragma once
#include "../Scene.h"
#include <SFML/Graphics/Text.hpp>

class Level : public Scene
{
protected:
	float mEndTimer;

public:
	virtual void Init();
	virtual void Update(float delta);
};

