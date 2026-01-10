#pragma once
#include <unordered_map>

class Action;

class Entity;

class StateMachine
{
protected:
	bool m_isActive = true;

	Entity* m_pOwner = nullptr;

	int m_currentState = -1;

	std::unordered_map<int, Action*> m_actions;

public:
	StateMachine(Entity* pOwner);
	~StateMachine();

	Action* GetAction(int state) { return m_actions[state]; }

	void AddAction(int state, Action* action);

	void ChangeState(int newState);

	void Update();

	Entity* GetOwner() { return m_pOwner; }

	void SetIsActive(bool b) { m_isActive = b; }
	const bool& IsActive() const { return m_isActive; }
};