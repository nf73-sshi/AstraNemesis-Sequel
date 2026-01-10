#include "ActionsBoss2.h"
#include "../Bosses/Boss2.h"
#include "../Important/GameManager.h"
#include "../Important/res.h"

ActionPatternGlobal::ActionPatternGlobal(float timer) : Action(timer)
{
}
void ActionPatternGlobal::OnStart()
{
	m_action_progress = 0.f;

	auto pOwner = GetOwner<Boss2>();

	pOwner->ResetVelocity(true, false);
}
void ActionPatternGlobal::OnUpdate()
{
	Action::OnUpdate();
	auto pOwner = GetOwner<Boss2>();
	float dt = GameManager::DeltaTime();

	pOwner->Slide(dt);
	pOwner->Shoot();
}
void ActionPatternGlobal::OnEnd()
{
}
void ActionPatternGlobal::OnTimeOut()
{
	auto pOwner = GetOwner<Boss2>();

	pOwner->Randomize();

	int rdm = pOwner->GetRandomizer();

	if (rdm <= 5.f)
		pOwner->GetStateMachine().ChangeState(PATTERN1);
	else
		pOwner->GetStateMachine().ChangeState(PATTERN2);
}

////////////////////////////////////////////////////////////////////

ActionPattern1::ActionPattern1(float timer) : Action(timer)
{
}
void ActionPattern1::OnStart()
{
	m_action_progress = 0.f;

	progress = 0.f;
}
void ActionPattern1::OnUpdate()
{
	Action::OnUpdate();

	auto pOwner = GetOwner<Boss2>();

	float dt = GameManager::DeltaTime();

	if (progress < shootingDelay)
	{
		progress += dt;
	}
	else
	{
		pOwner->SpawnBall(0, 800.f, 1, pOwner->getPosition(), { 1, 0 });
		pOwner->SpawnBall(0, 800.f, 1, pOwner->getPosition(), { -1, 0 });
		progress = 0.f;
	}

	if (back == false)
	{
		if (pOwner->DashForward(dt, 1000.f) == false)
			back = true;
	}
	else
	{
		if (pOwner->DashBackward(dt) == false)
		{
			back = false;
			pOwner->GetStateMachine().ChangeState(PATTERNGLOBAL);
		}
	}

}
void ActionPattern1::OnEnd()
{
}
void ActionPattern1::OnTimeOut()
{
	auto pOwner = GetOwner<Boss2>();

	pOwner->GetStateMachine().ChangeState(PATTERNGLOBAL);
}

////////////////////////////////////////////////////////////////////

ActionPattern2::ActionPattern2(float timer) : Action(timer)
{
}
void ActionPattern2::OnStart()
{
	m_action_progress = 0.f;

	auto pOwner = GetOwner<Boss2>();

	pOwner->ScaleVelocity(0.5f, 1.f);

	isActive = true;
}
void ActionPattern2::OnUpdate()
{
	Action::OnUpdate();

	if (isActive == false)
		return;

	auto pOwner = GetOwner<Boss2>();
	float dt = GameManager::DeltaTime();
	 
	pOwner->Slide(dt);

	if (progressShootingDelay < 0.f)
	{
		for (int i = 0; i < amount; i++)
		{
			float angle = (i + 1) * PI / amount;

			pOwner->SpawnBall(0, 600.f, 1.f, pOwner->getPosition(), { cos(angle), sin(angle) });
		}

		progressShootingDelay = shootingDelay;
	}
	else
	{
		progressShootingDelay -= dt;
	}
}
void ActionPattern2::OnEnd()
{

}
void ActionPattern2::OnTimeOut()
{
	isActive = false;

	auto pOwner = GetOwner<Boss2>();

	if (progressEndDelay < endDelay)
	{
		progressEndDelay += GameManager::DeltaTime();
	}
	else
	{
		progressEndDelay = 0.f;
		pOwner->GetStateMachine().ChangeState(PATTERNGLOBAL);
	}
}
