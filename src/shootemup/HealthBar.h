#pragma once
#include "Entity.h"

class HealthBar : public Entity 
{
protected:
	sf::RectangleShape mHpBarFilled;
	sf::RectangleShape mHpBarEmpty;
  
public:
	HealthBar();

	void Update(float delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape* GetMHpBarFilled();
	sf::RectangleShape* GetMHpBarEmpty();

	void UpdateBar(float ratio);
};

