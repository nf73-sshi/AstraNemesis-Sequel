#pragma once
#include "../Actions/Action.h"

class ActionPatternGlobal : public Action
{
public:
	ActionPatternGlobal(float timer);

	void OnStart() override;
	void OnUpdate() override;
	void OnEnd() override;
	void OnTimeOut() override;
};


class ActionPattern1 : public Action
{
	bool back = false;

	float shootingDelay = 0.2f;
	float progress = 0.f;
public:
	ActionPattern1(float timer);

	void OnStart() override;
	void OnUpdate() override;
	void OnEnd() override;
	void OnTimeOut() override;
};

class ActionPattern2 : public Action
{
	int amount = 10;
	float shootingDelay = 0.25f;
	float progressShootingDelay = shootingDelay;

	float endDelay = 0.75f;
	float progressEndDelay = 0.f;

	bool isActive = true;
public:
	ActionPattern2(float timer);

	void OnStart() override;
	void OnUpdate() override;
	void OnEnd() override;
	void OnTimeOut() override;
};