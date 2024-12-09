#include "Scene.h"

void Scene::Update(float deltatime)
{
	for (int i = 0; i < arrayEntity.size(); ++i) {
		arrayEntity[i]->Update(deltatime);
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
