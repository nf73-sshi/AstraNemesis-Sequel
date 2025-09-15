#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    bool mDestroy = false;
    sf::Vector2f mDirection = { 0, 0 };
    sf::Vector2f origin;
public:
    int mDrawPriority = 0;

    void CreateSprite(const char* alias, int x, int y, int sizeX, int sizeY);

    sf::Sprite& GetSprite() { return sprite; }
    bool GetMDestroy();

    virtual int GetDamage();

    virtual float GetRatioHP();

    virtual bool IsDead();

    void SetPosition(sf::Vector2f pos);
    void SetPosition(float x, float y);

    Entity* GetEntity(); // 0 IQ

    void SetMDestroy(bool value); 

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void Update(float delta) = 0;

};

