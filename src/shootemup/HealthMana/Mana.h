#pragma once

class Mana
{

protected:
	int mCurrentMana;
	int mMaxMana;
	float mManaReload;
	float mProgress = 0.f;
public:
	Mana(); 

	void FillManaBar();

	int* GetCurrentMana();
	void SetCurrentMana(int value);
	void AddRemoveMana(int value);

	int GetMaxMana();
	void SetMaxMana(float value);
	void AddRemoveMaxMana(int value);

	float GetRatioMana();

	float GetManaReload();
	void SetManaReload(float value);
	void AddRemoveManaReload(float value);
};

