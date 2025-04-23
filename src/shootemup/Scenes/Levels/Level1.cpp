#include "Level1.h"
#include "../../Important/res.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/GameManager.h"
#include "../../Bosses/Boss1.h"
#include "../../PlayerMobs/Mob1.h"


void Level1::Init()
{
	Level::Init();

	ABoss* pBoss = new Boss1();
	pBoss->setOrigin(266.5f, 127.5f);
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.4, 127.5); 

	HealthBar* pBossHB = new HealthBar(400.f, 30.f);
	pBoss->SetLifeBar(pBossHB);
	pBossHB->GetMHpBarFilled()->setPosition(250, 30);
	pBossHB->GetMHpBarEmpty()->setPosition(250, 30);

	addEntity(pBoss); 
	addEntity(pBossHB);

	InitUI();
}

void Level1::Update(float delta)
{	
	Level::Update(delta);

	if (Scene::GetAll<ABoss>().size() + Scene::GetAll<Mob1>().size() <= 0)
	{
		mEndTimer -= delta;

		if (mEndTimer <= 0.f)
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Menu");
	}
}
