#pragma once
#include "../Others/Entity.h"

class ManaBar : public Entity
{
protected:
	sf::RectangleShape mManaBarFilled;
	sf::RectangleShape mManaBarEmpty;

public:
	ManaBar(); 

	void Update(float delta) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape* GetManaBarFilled();
	sf::RectangleShape* GetManaBarEmpty();

	void UpdateBar(float ratio);
};

