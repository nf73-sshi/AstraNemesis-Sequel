#include "Scene.h"
#include "../Others/Collide.h"
#include <iostream>

void Scene::Update(float delta)
{
	mousePos = sf::Mouse::getPosition();

	for (int i = 0; i < arrayEntity.size(); i++)
	{
		arrayEntity[i]->Update(delta); 
		Collide* c = dynamic_cast<Collide*>(arrayEntity[i]);
		if (c)
		{
			for (int j = 0; j < arrayEntity.size(); ++j)
			{
				Collide* other = dynamic_cast<Collide*>(arrayEntity[j]);
				if (other && other != c)
				{
					if (c->CheckCollision(other))
					{
						c->OnCollide(arrayEntity[j]);
						other->OnCollide(arrayEntity[i]);
					}
				}
			}
		}
	}
	for (auto it = arrayEntity.begin(); it != arrayEntity.end();)
	{
		if ((*it)->GetMDestroy())
		{
			delete* it;
			it = arrayEntity.erase(it);
		}
		else 
		{
			++it;
		}
	}
}

Scene::~Scene()
{
	Clear();
}

void Scene::Clear()
{
	for (Entity* e: arrayEntity)
	{
		delete e;
	}
	arrayEntity.clear();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < arrayEntity.size(); ++i)
	{
		target.draw(*(arrayEntity[i]), states);
	}
}

void Scene::addEntity(Entity* e)
{
	arrayEntity.push_back(e);
}

