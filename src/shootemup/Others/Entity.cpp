#include "Entity.h"
#include <iostream>
#include <string> 
#include "../Important/AssetManager.h"
#include "Convert.h"

void Entity::CreateSprite(const char* alias, int x, int y, int sizeX, int sizeY)
{
    mDestroy = false;
    sf::Texture* tmpTexture = AssetManager::Get()->GetTexture(alias);
    if (tmpTexture)
    {
        texture = *tmpTexture;
        sprite.setTexture(texture);

        if (x == y && sizeX == sizeY && x + y + sizeX + sizeY == -4)
        {
        }
        else
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

void Entity::SetPosition(sf::Vector2f pos)
{
    auto resizedPos = Convert::AdaptToWindow(pos);

    setPosition(resizedPos);
}

void Entity::SetPosition(float x, float y)
{
    SetPosition(sf::Vector2f(x, y));
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

sf::Vector2f Entity::GetSpriteSize()
{
    sf::FloatRect rect = sprite.getGlobalBounds();

    return sf::Vector2f(rect.width * getScale().x, rect.height * getScale().y);
}

float Entity::GetSpecificScale(bool includeX, bool includeY)
{
    if (includeX == false && includeY == false)
        return 0.f;

    sf::Vector2f scale = getScale();

    if (includeX == false)
        return scale.y;

    if (includeY == false)
        return scale.x;

    return (scale.x + scale.y) * 0.5f;
}

float Entity::GetMaxScale(bool state)
{
    if (state)
        return std::max(getScale().x, getScale().y);
    else
        return std::min(getScale().x, getScale().y);
}
