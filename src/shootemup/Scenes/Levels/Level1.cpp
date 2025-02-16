#include "Level1.h"
#include "../../PlayerMobs/Player.h"
#include "../../Sprites/Background.h"
#include "../../Sprites/UI.h"
#include "../../HealthMana/HealthBar.h"
#include "../../HealthMana/ManaBar.h"
#include "../../Bosses/Boss1.h"
#include "../../PlayerMobs/Mob1.h"
#include <iostream>
#include "../../Important/res.h"


void Level1::Init()
{
	playerPos.x = 0;
	playerPos.y = 0;
	mCurrentTimer = 0;
	mEndTimer = 0;

	Player* pPlayer = new Player();

	GameManager::GetInstance()->SetCurrentPlayer(pPlayer);

	pPlayer->setOrigin(32, 32);
	pPlayer->scale(1.5, 1.5);
	pPlayer->setPosition(WINDOW_WIDTH * 0.4, WINDOW_HEIGHT * 0.7);


	ABoss* pBoss = new Boss1();
	pBoss->setOrigin(266.5f, 127.5f);
	pBoss->scale(2, 1);
	pBoss->setPosition(WINDOW_WIDTH * 0.4, 127.5);


	Background* pBG = new Background();
	pBG->setOrigin(960, 0);
	pBG->setPosition(WINDOW_WIDTH * 0.5, -1080);

	UI* pUI = new UI();
	pUI->setOrigin(75, 270);
	pUI->setScale(2, 2);
	pUI->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT * 0.5);

	HealthBar* pPlayerHB = new HealthBar();
	pPlayerHB->GetMHpBarFilled()->setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);
	pPlayerHB->GetMHpBarEmpty()->setPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);
	pPlayer->SetLifeBar(pPlayerHB);

	HealthBar* pBossHB = new HealthBar();
	pBossHB->GetMHpBarFilled()->setPosition(WINDOW_WIDTH - 250, 30);
	pBossHB->GetMHpBarEmpty()->setPosition(WINDOW_WIDTH - 250, 30);
	pBoss->SetLifeBar(pBossHB);

	ManaBar* pManaB = new ManaBar();
	pManaB->GetManaBarFilled()->setPosition(WINDOW_WIDTH - 275, WINDOW_HEIGHT - 120); 
	pManaB->GetManaBarEmpty()->setPosition(WINDOW_WIDTH - 275, WINDOW_HEIGHT - 120); 
	pPlayer->SetManaBar(pManaB);  

	addEntity(pBG);

	addEntity(pPlayer);
	addEntity(pBoss); 
	addEntity(pUI);

	addEntity(pPlayerHB);
	addEntity(pManaB);
	addEntity(pBossHB);
}

void Level1::Update(float delta)
{
	GetPosition(GameManager::GetInstance()->GetCurrentPlayer());

	Scene::Update(delta);

	mCurrentTimer += delta;
	var += delta;

	if (Scene::GetAll<Player>().size() <= 0)
	{
		std::cout << "LOSE\n";
		mEndTimer += delta;

		if (mEndTimer > 2.f)
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("GameOver");
	}

	if (Scene::GetAll<ABoss>().size() + Scene::GetAll<Mob1>().size() <= 0)
	{
		std::cout << "WIN\n";
		mEndTimer += delta;

		if (mEndTimer > 2.f)
			GameManager::GetInstance()->GetCurrentSceneManager().ChangeScene("Menu");
	}

	std::cout << "Mana : " << *(GameManager::GetInstance()->GetCurrentPlayer()->GetCurrentMana()) << std::endl;

}

void Level1::GetPosition(Entity* pPlayer)
{ 
	playerPos = pPlayer->getPosition(); 
}

