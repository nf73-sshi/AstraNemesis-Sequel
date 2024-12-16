#pragma once
#include "Entity.h"
#include "Ball.h"
#include "Character.h"

class Player : public Character, public Collide
{
	sf::CircleShape mPlayerHitbox;
	bool mIsInvincible;
	float mTimerInvincible;

public:
	Player(const char* name, int hp, int damage, float speed, float shootingDelay);

	void Move(float delta);

	void Shoot() override;

	void ScreenCollision();

	void BeInvincible();

	void ResetInvincible(float delta);

	void Update(float delta) override;


	// Hérité via Collide
	Hitbox GetHitbox() override;

	void OnCollide(Entity* e) override;

};

