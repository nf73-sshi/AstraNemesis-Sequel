#pragma once
#include "../Others/Entity.h"

class HealthBar : public Entity 
{
protected:
	sf::RectangleShape mHpBarFilled;
	sf::RectangleShape mHpBarEmpty;
	sf::RectangleShape mLight; // Decoration
	sf::RectangleShape mShadow; // Decoration

	float mLength = 0;
	float mWidth = 0;

	float mCurrentRatio = 1;
	float alpha = 255;

	float varColor1;
	float varColor2;
public:
	bool fading = true;
	bool showAfterDying = false;

	HealthBar(float length, float width);

	void Update(float delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape* GetMHpBarFilled();
	sf::RectangleShape* GetMHpBarEmpty();

	sf::Vector2f GetSize() { return sf::Vector2f(mLength, mWidth); }

	void SetBarPosition(float x, float y);

	void UpdateBar(float ratio);
};

