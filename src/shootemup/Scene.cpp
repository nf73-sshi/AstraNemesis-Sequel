#include "Scene.h"

void Scene::Update(float delta)
{
	for (int i = 0; i < arrayEntity.size(); ++i) {
		arrayEntity[i]->Update(delta);
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
