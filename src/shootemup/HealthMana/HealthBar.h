#pragma once
#include "../Others/Entity.h"

class HealthBar : public Entity 
{
protected:
	sf::RectangleShape mHpBarFilled;
	sf::RectangleShape mHpBarEmpty;

	float mLength;
	float mWidth;
public:
	HealthBar(float length, float width);

	void Update(float delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape* GetMHpBarFilled();
	sf::RectangleShape* GetMHpBarEmpty();

	void UpdateBar(float ratio);
};

