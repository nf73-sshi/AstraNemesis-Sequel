#include "Level.h"
#include <iostream>
#include "../../Important/res.h"
#include "../../PlayerMobs/Player.h"
#include "../../Sprites/Background.h"
#include "../../Sprites/UI.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/GameManager.h"
#include "../../HealthMana/ManaBar.h"
#include "../../Bosses/ABoss.h"
#include "../../PlayerMobs/Mob.h"
#include "../../Skills/UI_Skills.h"

void Level::Init()
{
	mEndTimer = 1.f;
	mIsWon = false;

	pCurrentPlayer = new Player();

	GameManager::Get()->SetCurrentPlayer(pCurrentPlayer);

	pCurrentPlayer->scale(1.5, 1.5);
	pCurrentPlayer->setPosition(WINDOW_WIDTH * 0.4, WINDOW_HEIGHT * 0.7);

	Background* pBG = new Background();

	addEntity(pBG);
	addEntity(pCurrentPlayer);

	InitUI();
}

void Level::InitUI()
{
	//Interface
	UI* pUI = new UI();
	pUI->setScale(2, 2);
	pUI->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT * 0.5);
	addEntity(pUI);

	const char* name1 = "SkillBallX2";
	UI_Skills* pSkillBallX2 = new UI_Skills(name1, pCurrentPlayer->GetSkill(name1));
	pSkillBallX2->setPosition(WINDOW_WIDTH - 225, WINDOW_HEIGHT - 180);
	addEntity(pSkillBallX2);

	const char* name2 = "SkillHeal";
	UI_Skills* pSkillHeal = new UI_Skills(name2, pCurrentPlayer->GetSkill(name2));
	pSkillHeal->setPosition(WINDOW_WIDTH - 150, WINDOW_HEIGHT - 180);
	addEntity(pSkillHeal);
	/////
	
	// BARS
	HealthBar* pPlayerHB = new HealthBar(200.f, 30.f);
	pCurrentPlayer->SetLifeBar(pPlayerHB);
	pPlayerHB->SetBarPosition(WINDOW_WIDTH - 250, WINDOW_HEIGHT - 60);
	pPlayerHB->showAfterDying = true;
	addEntity(pPlayerHB);

	ManaBar* pManaB = new ManaBar(220.f, 30.f);
	pManaB->SetBarPosition(WINDOW_WIDTH - 260, WINDOW_HEIGHT - 120);
	pCurrentPlayer->SetManaBar(pManaB);
	addEntity(pManaB);
	////////

}

void Level::Update(float delta)
{
	Scene::Update(delta);

	if (Scene::GetAll<Player>().size() <= 0)
	{
		mEndTimer -= delta;

		if (mEndTimer <= 0)
		{
			GameManager::Get()->GetCurrentSceneManager().ChangeScene("GameOver");
		}
	}

	if (infinite)
		return;

	if (Scene::GetAll<ABoss>().size() + Scene::GetAll<Mob>().size() <= 0 && pCurrentPlayer->Health::IsDead() == false)
	{
		pCurrentPlayer->SetInvincible(true);

		auto jingle = AssetManager::Get()->GetSound("Winning");

		if (mIsWon == false)
		{
			AssetManager::Get()->StopAllMusics();
			jingle->play();
			mIsWon = true;
		}

		if (jingle->getStatus() == sf::Sound::Status::Stopped)
		{
			GameManager::Get()->GetCurrentSceneManager().ChangeScene("Menu");
		}
	}
}
