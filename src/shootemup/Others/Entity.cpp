#include "Entity.h"
#include <iostream>
#include <string> 
#include "../Important/AssetManager.h"

void Entity::CreateSprite(const char* alias, int x, int y, int sizeX, int sizeY)
{
    mDestroy = false;
    sf::Texture* tmpTexture = AssetManager::Get()->GetTexture(alias);
    if (tmpTexture)
    {
        texture = *tmpTexture;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(x, y, sizeX, sizeY));

        sf::FloatRect bounds = sprite.getGlobalBounds();

        origin = { bounds.width * 0.5f, bounds.height * 0.5f };

        setOrigin(origin);
    }
    else
    {
        std::cout << "Erreur : " << alias << " n'a pas pu etre initialise !\n";
    }
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
