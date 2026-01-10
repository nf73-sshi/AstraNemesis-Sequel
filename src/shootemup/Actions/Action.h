#pragma once

class Entity;

class Action
{
protected:
	Entity* m_pOwner = nullptr;

	float m_action_timer = -1;
	float m_action_progress = 0.f;
public:
	Action() = default;
	Action(float timer) { m_action_timer = timer; }

	virtual void OnStart() = 0;
	virtual void OnUpdate();
	virtual void OnEnd() = 0;
	virtual void OnTimeOut() {};

	void SetOwner(Entity* pOwner) { m_pOwner = pOwner; }

	template<typename T>
	T* GetOwner() { return dynamic_cast<T*>(m_pOwner); }

	void ChangeTimer(float time) { m_action_timer = time; }
	void ResetProgress() { m_action_progress = 0.f; }
};

