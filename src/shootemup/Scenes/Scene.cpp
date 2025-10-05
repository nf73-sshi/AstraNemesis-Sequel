#include "Scene.h"
#include "../Others/Collide.h"
#include "../Important/GameManager.h"
#include "../Important/Debug.h"
#include <iostream>
#include <map>

void Scene::Update(float delta)
{
	mousePos = sf::Mouse::getPosition();

	for (int i = 0; i < arrayEntity.size(); i++)
	{
		arrayEntity[i]->Update(delta);
		Collide* c = dynamic_cast<Collide*>(arrayEntity[i]);

		if (c)
		{
			c->GetHitbox().Draw();

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
	for (auto it = arrayTextes.begin(); it != arrayTextes.end();)
	{
		if (false)
		{
			delete* it;
			it = arrayTextes.erase(it);
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
	for (Entity* e : arrayEntity)
	{
		delete e;
	}
	arrayEntity.clear();

	for (sf::Text* t : arrayTextes)
	{
		delete t;
	}
	arrayTextes.clear();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::vector<std::vector<Entity*>> arrayEntityOrder;

	std::vector<Entity*> empty; 

	for (int i = 0; i < 10; ++i)
	{
		arrayEntityOrder.push_back(empty); 
	}

	for (Entity* e : arrayEntity)
	{
		arrayEntityOrder[e->mDrawPriority].push_back(e);
	}

	for (int i = 0; i < 10; ++i)
	{
		for (Entity* e : arrayEntityOrder[i])
		{
			target.draw(*e, states);
		}
	}

	Debug::Get()->DrawAll(target, states);

	for (sf::Text* t : arrayTextes)
	{
		target.draw(*t, states);
	}

	arrayEntityOrder.clear();
}

void Scene::addEntity(Entity* e)
{
	arrayEntity.push_back(e);
}
