#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Debug
{
	static Debug* mInstance;

	std::vector<sf::CircleShape> circles;
	std::vector<sf::RectangleShape> rects;
	std::vector<sf::Text> textes;
public:
	static Debug* Get();

	void DrawAll(sf::RenderTarget& target, sf::RenderStates states) const;

	static void DrawFilledCircle(sf::Vector2f pos, float radius, sf::Color color);
	static void DrawFilledCircle(float x, float y, float radius, sf::Color color);

	static void DrawFilledRect(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
	static void DrawFilledRect(float x, float y, sf::Vector2f size, sf::Color color);

	static void DrawDetailledCircle(sf::Vector2f pos, float radius, sf::Color fillColor, float outlineThickness, sf::Color outlineColor);
	static void DrawDetailledCircle(float x, float y, float radius, sf::Color fillColor, float outlineThickness, sf::Color outlineColor);

	static void DrawDetailledRect(sf::Vector2f pos, sf::Vector2f size, sf::Color fillColor, float outlineThickness, sf::Color outlineColor);
	static void DrawDetailledRect(float x, float y, sf::Vector2f size, sf::Color fillColor, float outlineThickness, sf::Color outlineColor);

	static void DrawText(std::string txt, sf::Vector2f pos, int size, sf::Color color, float ratioX = 0.5f, float ratioY = 0.5f);
	static void DrawText(std::string txt, float x, float y, int size, sf::Color color, float ratioX = 0.5f, float ratioY = 0.5f);
};

