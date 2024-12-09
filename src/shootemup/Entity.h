#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
    sf::Texture texture;
    sf::Sprite sprite;

public:

    void CreateSprite(const char* link, int x, int y, int sizeX, int sizeY);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void Update(float delta) = 0;

};

