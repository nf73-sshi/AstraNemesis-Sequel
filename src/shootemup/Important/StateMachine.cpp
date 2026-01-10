#include "StateMachine.h"
#include "../Actions/Action.h"

StateMachine::StateMachine(Entity* pOwner)
{
	m_pOwner = pOwner;
}

StateMachine::~StateMachine()
{
	for (auto it = m_actions.begin(); it != m_actions.end();)
	{
		delete it->second;

		it = m_actions.erase(it);
	}

	m_actions.clear();
}

void StateMachine::AddAction(int state, Action* action)
{
	action->SetOwner(m_pOwner);
	m_actions[state] = action;
}

void StateMachine::ChangeState(int newState)
{
	if(newState > m_actions.size())
		return;
	
	if (m_currentState != -1)
	{
		m_actions[m_currentState]->OnEnd();
		m_actions[m_currentState]->ResetProgress();
	}

	m_currentState = newState;

	m_actions[newState]->OnStart();
}

void StateMachine::Update()
{
	if (m_currentState == -1)
		return;

	if (m_isActive == false)
		return;

	m_actions[m_currentState]->OnUpdate();
}