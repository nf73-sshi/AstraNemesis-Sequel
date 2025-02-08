#pragma once
#include "../Others/Entity.h"
#include "../Others/Collide.h"
#include "../Important/GameManager.h"


class Ball : public Entity, public Collide
{

protected:
	int mDamage;
	float mSpeed;
	float mScale;
	float mXFactor;
	float mYFactor;
	float mCurrentTime;
	Scene* mCurrentScene;

public:
	Ball(int damage, float speed, float size, float xFactor, float yFactor);

	int GetDamage();
	float GetSpeed();
	float GetXFactor();
	float GetYFactor();

	void SetSize(float size);
	void SetDamage(int damage);
	void SetSpeed(float speed);
	void SetDirection(float xFactor, float yFactor);

	void Update(float delta) override;

	// Hérité via Collide
	Hitbox GetHitbox() override;
	virtual void OnCollide(Entity*);
};

