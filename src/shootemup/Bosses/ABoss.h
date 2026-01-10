#pragma once
#include "../Others/Character.h"
#include "../Others/Collide.h"

class HealthBar;
class EnemyBall;

class ABoss : public Character, public Collide
{
protected:
	float mVelocityX;
	float mVelocityY;

	int mRandomizer;
	HealthBar* mHB;

	float mScaleBall;
	float mAtkSpeed;

public:
	ABoss(const char* name, int hp, int damage, float speed, float shootingDelay, float atkSpeed, float scaleBall);

	virtual void Update(float delta);

	virtual void Shoot() = 0;

	const int& GetRandomizer() const { return mRandomizer; }
	void Randomize();

	void SetLifeBar(HealthBar* pHB);
	virtual void OnCollide(Entity* e);

	const sf::Vector2f GetVelocity() const {return { mVelocityX, mVelocityY };}
	void SetVelocity(float x = -1, float y = -1) { if(x != -1)mVelocityX = x; if(y != -1)mVelocityY = y; }
	void ResetVelocity(bool includeX, bool includeY)
	{
		int sign1 = 0, sign2 = 0;

		if (includeX)
		{
			if (mVelocityX >= 0.f)
				sign1 = 1;
			else
				sign1 = -1;

			mVelocityX = mSpeed * sign1;
		}

		if (includeY)
		{
			if (mVelocityY >= 0.f)
				sign2 = 1;
			else
				sign2 = -1;

			mVelocityY = mSpeed * sign2;
		}
	}
	void ScaleVelocity(float scaleX = 1.f, float scaleY = 1.f) { mVelocityX *= scaleX; mVelocityY *= scaleY; }
	EnemyBall* SpawnBall(int addDamage, float speed, float multiplyScale, sf::Vector2f pos, sf::Vector2f direction);
};

