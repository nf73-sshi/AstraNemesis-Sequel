#pragma once
#include "Entity.h"
#include "Ball.h"
#include "Character.h"

class Player : public Character, public Collide
{
	sf::CircleShape mPlayerHitbox;
	float mCurrentTimer;
public:
	Player(const char* name, int hp, int damage, float speed, float shootingDelay);

	void Shoot();

	void Update(float delta) override;



	// Hérité via Collide
	Hitbox GetHitbox() override;

	void OnCollide(Entity*) override;

};

