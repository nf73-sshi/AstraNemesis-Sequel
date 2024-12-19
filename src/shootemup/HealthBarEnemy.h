#pragma once
#include "Entity.h"

class HealthBarEnemy : public Entity
{

protected:
	sf::RectangleShape mHpBar;

public:
	HealthBarEnemy();

	void Update(float delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

