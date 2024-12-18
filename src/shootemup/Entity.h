#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    bool mDestroy;

public:

    void CreateSprite(const char* link, int x, int y, int sizeX, int sizeY);

    bool GetMDestroy();

    virtual int GetDamage();

    Entity* GetEntity();

    void SetMDestroy(bool value); 

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void Update(float delta) = 0;

};

