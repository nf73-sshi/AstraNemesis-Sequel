#pragma once
#include <SFML/Graphics.hpp>

class Entity;

class Hitbox
{
public:
	sf::Vector2f position;
	float radius;
	void Draw();
};

class Collide
{
public:
	virtual Hitbox GetHitbox() = 0;
	virtual void OnCollide(Entity* e) = 0;
	bool CheckCollision(Collide* other);

};

