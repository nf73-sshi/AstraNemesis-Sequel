#pragma once
#include "Scene.h"
class Level : public Scene
{
	float mCurrentTimer;

public:
	void Init();
	void Update(float delta) override;
};

