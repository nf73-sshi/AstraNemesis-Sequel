#pragma once
#include "Button.h"

class BackButton : public Button
{
	const char* mSceneToGo;
public:
	BackButton(const char* sceneName);
	void Update(float delta) override;
};

