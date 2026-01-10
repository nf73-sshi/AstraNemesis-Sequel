#pragma once
#include "ABoss.h"
#include "../Important/StateMachine.h"

enum StateBoss2
{
	PATTERNGLOBAL,
	PATTERN1,
	PATTERN2,
};

class Boss2 : public ABoss
{
	StateMachine m_SM;
public:
	Boss2();
	void Update(float dt) override;
	void Shoot() override;

	std::vector<Hitbox> GetHitboxes() override;

	bool DashForward(float dt, float maxPos);
	bool DashBackward(float dt);

	void Slide(float dt);

	StateMachine& GetStateMachine() { return m_SM; }
};

