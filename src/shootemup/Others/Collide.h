#pragma once
#include <SFML/Graphics.hpp>

class Entity;

class Hitbox
{
public:
	Hitbox(sf::Vector2f pos, float radius, sf::Vector2f offset = {0, 0}) { position = pos + offset; this->radius = radius; }

	sf::Vector2f position;
	float radius;
	void Draw();
};

class Collide
{
protected:
	float mHitboxSize = -1;

public:
	virtual std::vector<Hitbox> GetHitboxes() { return std::vector<Hitbox>(); }
	virtual void OnCollide(Entity* e) = 0;
	bool CheckCollision(Collide* other);
};

