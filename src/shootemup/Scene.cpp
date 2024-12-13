#include "Scene.h"
#include "Collide.h"
void Scene::Update(float delta)
{
	for (int i = 0; i < arrayEntity.size(); ++i) {
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
					}
				}
			}
		}
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < arrayEntity.size(); ++i) {
		target.draw(*(arrayEntity[i]), states);
	}
}

void Scene::addEntity(Entity* e)
{
	arrayEntity.push_back(e);
}

void Scene::removeEntity(Entity* e)
{
	//arrayEntity.erase(e);
}
