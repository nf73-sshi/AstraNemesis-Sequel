#pragma once

class Stats
{
	int mPlayerMaxMana;
	int mPlayerCurrentMana; // Prototype
	float mPlayerManaReload;
	int mMoney; // pas encore fait
	int mSkillBallX2Lvl;
	int mPlayerMaxHP;
	int mPlayerCurrentHP;
	int mPlayerDamage;
	float mPlayerSpeed;
	float mPlayerSDelay;

	void FillMana();
	void FillHP();
public:
	Stats();

	int GetPlayerMaxMana(); 
	int GetPlayerMana();
	int GetMoney();
	int GetSkillBallX2Lvl();
	int GetPlayerMaxHP();
	int GetPlayerHP();
	int GetPlayerDamage();
	float GetPlayerSpeed();
	float GetPlayerSDelay();

	void SetPlayerMaxMana(int value); 
	void SetPlayerMana(int value);
	void SetMoney(int value);
	void SetSkillBallX2Lvl(int value);
	void SetPlayerMaxHP(int value);
	void SetPlayerHP(int value);
	void SetPlayerDamage(int value);
	void SetPlayerSpeed(float value);
	void SetPlayerSDelay(float value);

	void AddPlayerMaxMana(int value);
	void AddPlayerMana(int value);
	void AddMoney(int value);
	void AddSkillBallX2Lvl(int value);
	void AddPlayerMaxHP(int value);
	void AddPlayerHP(int value);
	void AddPlayerDamage(int value);
	void AddPlayerSpeed(float value);
	void AddPlayerSDelay(float value);


	float GetPlayerManaReload();
	void SetPlayerManaReload(float value);
	void AddRemovePlayerManaReload(float value);
};

