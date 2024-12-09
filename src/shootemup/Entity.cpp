#include "Entity.h"
#include <iostream>

void Entity::CreateSprite(const char* link, int x, int y, int sizeX, int sizeY)
{

    if (!texture.loadFromFile(link))
    {
        std::cout << "Fichier non charge :" << link << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(x, y, sizeX, sizeY));

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());

    target.draw(sprite, states);
}
