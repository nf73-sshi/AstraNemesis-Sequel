#include "Scene.h"
#include "../Others/Collide.h"
#include "../Important/GameManager.h"
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

void Scene::DrawText(sf::Text* yourText, std::string text, float x, float y, int size, sf::Color color)
{
	sf::Text textToDisplay;

	textToDisplay.setFont(GameManager::GetInstance()->mFont);

	textToDisplay.setString(text);
	textToDisplay.setPosition(x, y);
	textToDisplay.setCharacterSize(size);
	textToDisplay.setFillColor(color);

	yourText = &textToDisplay;

	GameManager::GetInstance()->GetWindow()->draw(*yourText);
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

	arrayEntityOrder.clear();
}

void Scene::addEntity(Entity* e)
{
	arrayEntity.push_back(e);
}

