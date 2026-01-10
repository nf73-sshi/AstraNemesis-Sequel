#include "Action.h"
#include "../Important/GameManager.h"

void Action::OnUpdate()
{
	if (m_action_timer == -1)
		return;

	if (m_action_progress < m_action_timer)
		m_action_progress += GameManager::DeltaTime();
	else
	{
		OnTimeOut();
	}
}