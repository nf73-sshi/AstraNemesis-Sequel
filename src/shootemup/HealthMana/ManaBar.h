#pragma once
#include "../Others/Entity.h"

class ManaBar : public Entity
{
protected:
	sf::RectangleShape mManaBarFilled;
	sf::RectangleShape mManaBarEmpty;
	sf::RectangleShape mLight; // Decoration
	sf::RectangleShape mShadow; // Decoration

	float mLength = 0;
	float mWidth = 0;
public:
	ManaBar(float length, float width);

	void Update(float delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape* GetManaBarFilled();
	sf::RectangleShape* GetManaBarEmpty();

	void SetBarPosition(float x, float y);

	sf::Vector2f GetSize() { return sf::Vector2f(mLength, mWidth); }

	void UpdateBar(float ratio);
};

