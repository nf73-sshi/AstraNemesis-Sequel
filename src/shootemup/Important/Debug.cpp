#include "Debug.h"
#include "GameManager.h"

Debug* Debug::mInstance = nullptr;

Debug* Debug::Get()
{
	if (mInstance == nullptr)
	{
		mInstance = new Debug();
	}

	return mInstance;
}

void Debug::DrawAll(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = rects.begin(); it != rects.end();)
	{
		target.draw(*it, states);

		it = Debug::Get()->rects.erase(it);
	}

	for (auto it = circles.begin(); it != circles.end();)
	{
		target.draw(*it, states);

		it = Debug::Get()->circles.erase(it);
	}

	for (auto it = textes.begin(); it != textes.end();)
	{
		target.draw(*it, states);

		it = Debug::Get()->textes.erase(it);
	}
}

void Debug::DrawFilledCircle(sf::Vector2f pos, float radius, sf::Color color)
{
	sf::CircleShape e;
	e.setRadius(radius);
	e.setOrigin(e.getRadius(), e.getRadius());
	e.setFillColor(color);
	e.setPosition(pos);

	Debug::Get()->circles.push_back(e);
}
void Debug::DrawFilledCircle(float x, float y, float radius, sf::Color color)
{
	DrawFilledCircle({ x, y }, radius, color);
}

void Debug::DrawFilledRect(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
	sf::RectangleShape e;
	e.setSize(size);
	e.setOrigin(size.x / 2, size.y / 2);
	e.setFillColor(color);
	e.setPosition(pos);

	Debug::Get()->rects.push_back(e);
}
void Debug::DrawFilledRect(float x, float y, sf::Vector2f size, sf::Color color)
{
	DrawFilledRect({ x ,y }, size, color);
}

void Debug::DrawDetailledCircle(sf::Vector2f pos, float radius, sf::Color fillColor, float outlineThickness, sf::Color outlineColor)
{
	sf::CircleShape e;
	e.setRadius(radius);
	e.setOrigin(e.getRadius(), e.getRadius());
	e.setFillColor(fillColor);
	e.setOutlineThickness(outlineThickness);
	e.setOutlineColor(outlineColor);
	e.setPosition(pos);

	Debug::Get()->circles.push_back(e);
}
void Debug::DrawDetailledCircle(float x, float y, float radius, sf::Color fillColor, float outlineThickness, sf::Color outlineColor)
{
	DrawDetailledCircle({x, y}, radius, fillColor, outlineThickness, outlineColor);
}

void Debug::DrawDetailledRect(sf::Vector2f pos, sf::Vector2f size, sf::Color fillColor, float outlineThickness, sf::Color outlineColor)
{
	sf::RectangleShape e;
	e.setSize(size);
	e.setOrigin(size.x / 2, size.y / 2);
	e.setFillColor(fillColor);
	e.setOutlineThickness(outlineThickness);
	e.setOutlineColor(outlineColor);
	e.setPosition(pos);

	Debug::Get()->rects.push_back(e);
}
void Debug::DrawDetailledRect(float x, float y, sf::Vector2f size, sf::Color fillColor, float outlineThickness, sf::Color outlineColor)
{
	DrawDetailledRect({ x, y }, size, fillColor, outlineThickness, outlineColor);
}

void Debug::DrawText(std::string txt, sf::Vector2f pos, int size, sf::Color color, float ratioX, float ratioY)
{
	sf::Vector2f ratio = { ratioX, ratioY };

	if (ratio.x < 0 || ratio.x > 1)
	{
		ratio.x = 0.5f;
	}
	
	if (ratio.y < 0 || ratio.y > 1)
	{
		ratio.y = 0.5f;
	}
	
	sf::Text text;

	text.setFont(GameManager::Get()->mFont);

	text.setString(txt);
	text.setPosition(pos);
	text.setCharacterSize(size);
	text.setFillColor(color);

	const sf::FloatRect& bounds = text.getLocalBounds();
	text.setOrigin(bounds.width * ratio.x, bounds.height * ratio.y);

	Debug::Get()->textes.push_back(text);
}

void Debug::DrawText(std::string txt, float x, float y, int size, sf::Color color, float ratioX, float ratioY)
{
	DrawText(txt, { x, y }, size, color, ratioX, ratioY);
}
