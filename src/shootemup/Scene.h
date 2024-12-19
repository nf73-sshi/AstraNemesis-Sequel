#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Scene : public sf::Drawable
{

protected:
	std::vector<Entity*> arrayEntity; 
	sf::Vector2i mousePos;
	sf::RenderWindow* mWindow;
	
public:
	~Scene();
	virtual void Init() = 0;
	void Clear();
	virtual void Update(float delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void addEntity(Entity* e);
};

