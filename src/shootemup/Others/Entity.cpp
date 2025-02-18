#include "Entity.h"
#include <iostream>
#include <string> 

void Entity::CreateSprite(std::string link, int x, int y, int sizeX, int sizeY)
{
    mDestroy = false;
    if (!texture.loadFromFile(link))
    {
        if (!texture.loadFromFile("../../../" + link))
        {
        }
        else
        {
            std::cout << "Successfuly 2nd Path : " << "../../../" + link << std::endl; 
        }
    }
    else
    {
        std::cout << "Successfuly 1st Path : " << link << std::endl; 
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

bool Entity::IsDead()
{
    return false;
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
