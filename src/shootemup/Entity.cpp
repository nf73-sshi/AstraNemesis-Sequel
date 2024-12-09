#include "Entity.h"

void Entity::CreateSprite(const char* link)
{

    if (!texture.loadFromFile(link))
    {
        // error...
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());

    target.draw(sprite, states);
}
