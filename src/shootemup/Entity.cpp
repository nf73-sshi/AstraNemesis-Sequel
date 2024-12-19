#include "Entity.h"
#include <iostream>

void Entity::CreateSprite(const char* link, int x, int y, int sizeX, int sizeY)
{
    mDestroy = false;
    if (!texture.loadFromFile(link))
    {
        std::cout << "Fichier non charge :" << link << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(x, y, sizeX, sizeY));

}

bool Entity::GetMDestroy() 
{
    return mDestroy;
}

int Entity::GetDamage()
{
    return 0;
}

float Entity::GetRatioHP()
{
    return 1;
}

Entity* Entity::GetEntity()
{
    return this;
}

void Entity::SetMDestroy(bool value)
{
    mDestroy = value;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());

    target.draw(sprite, states);
}
