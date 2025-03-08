#pragma once

class Stats
{
	int mPlayerMaxMana = 100;
	int mPlayerCurrentMana = (int) ((float)mPlayerMaxMana * 0.5f); // Prototype
	float mPlayerManaReload = 0.5f;
	int mMoney = 0; // pas encore fait

	//BEGIN SKILLS
	int mSkillBallX2Lvl = 1;
	int mSkillHealLvl = 1;
	//END SKILLS

	int mPlayerMaxHP = 5;
	int mPlayerCurrentHP = mPlayerMaxHP;
	int mPlayerDamage = 10;
	float mPlayerSpeed = 750.f;
	float mPlayerSDelay = 0.2f;

	void FillMana();
	void FillHP();
public:
	int GetPlayerMaxMana() { return mPlayerMaxMana; }
	int GetPlayerMana() { return mPlayerCurrentMana; }
	int GetMoney() { return mMoney; }

	//BEGIN SKILLS
	int GetSkillBallX2Lvl() { return mSkillBallX2Lvl; }
	int GetSkillHealX2Lvl() { return mSkillHealLvl; }
	//END SKILLS

	int GetPlayerMaxHP() { return mPlayerMaxHP; }
	int GetPlayerHP() { return mPlayerCurrentHP; }
	int GetPlayerDamage() { return mPlayerDamage; }
	float GetPlayerSpeed() { return mPlayerSpeed; }
	float GetPlayerSDelay() { return mPlayerSDelay; }
	float GetPlayerManaReload() { return mPlayerManaReload; }

	void SetPlayerMaxMana(int value); 
	void SetPlayerMana(int value);
	void SetMoney(int value);

	//BEGIN SKILLS
	void SetSkillBallX2Lvl(int value);
	//END SKILLS

	void SetPlayerMaxHP(int value);
	void SetPlayerHP(int value);
	void SetPlayerDamage(int value);
	void SetPlayerSpeed(float value);
	void SetPlayerSDelay(float value);
	void SetPlayerManaReload(float value);

	void AddPlayerMaxMana(int value);
	void AddPlayerMana(int value);
	void AddMoney(int value);

	//BEGIN SKILLS
	void AddSkillBallX2Lvl(int value);
	//END SKILLS

	void AddPlayerMaxHP(int value);
	void AddPlayerHP(int value);
	void AddPlayerDamage(int value);
	void AddPlayerSpeed(float value);
	void AddPlayerSDelay(float value);
	void AddRemovePlayerManaReload(float value);
};

