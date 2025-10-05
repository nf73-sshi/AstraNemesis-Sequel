#pragma once
#include <SFML/Graphics.hpp>
#include "../Others/Entity.h"

class Scene : public sf::Drawable
{

protected:
	std::vector<Entity*> arrayEntity; 
	sf::Vector2i mousePos;
	sf::RenderWindow* mWindow;
	std::vector<sf::Text*> arrayTextes;
public:
	~Scene();
	virtual void Init() = 0;
	void Clear();
	virtual void Update(float delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void addEntity(Entity* e);

	template<typename T>
	T* GetFirst();

	template<typename T>
	std::vector<T*> GetAll();
};

template<typename T>
inline T* Scene::GetFirst()
{
	for (Entity* e : arrayEntity)
	{
		if (T* t = dynamic_cast<T*>(e))
		{
			return t;
		}
	}

	return nullptr;
}

template<typename T>
inline std::vector<T*> Scene::GetAll()
{
	std::vector<T*> arrayT;

	for (Entity* e : arrayEntity)
	{
		if (T* t = dynamic_cast<T*>(e))
		{
			arrayT.push_back(t);
		}
	}

	return arrayT;
}
