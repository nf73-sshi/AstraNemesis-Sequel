#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Scene : public sf::Drawable
{
	std::vector<Entity*> arrayEntity; 
	
public:
	virtual void Init() = 0;
	virtual void Update(float delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void addEntity(Entity* e);
	void removeEntity(Entity* e);
};

