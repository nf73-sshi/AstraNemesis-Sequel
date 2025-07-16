#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include "../Important/res.h"

namespace Convert
{
	static float GetRatio()
	{
		float ratioX = static_cast<float>(WINDOW_WIDTH) / BASE_WIN_WIDTH;
		float ratioY = static_cast<float>(WINDOW_HEIGHT) / BASE_WIN_HEIGHT;

		return (ratioX + ratioY) / 2;
	}

	static sf::Vector2f AdaptToWindow(float x, float y)
	{
		float scaleX = static_cast<float>(WINDOW_WIDTH) / BASE_WIN_WIDTH;
		float scaleY = static_cast<float>(WINDOW_HEIGHT) / BASE_WIN_HEIGHT;

		return sf::Vector2f(x * scaleX, y * scaleY);
	}

	static sf::Vector2f AdaptToWindow(sf::Vector2f pos)
	{
		return AdaptToWindow(pos.x, pos.y);
	}

	static float AdaptToWindow(float val)
	{
		float ratioX = static_cast<float>(WINDOW_WIDTH) / BASE_WIN_WIDTH;
		float ratioY = static_cast<float>(WINDOW_HEIGHT) / BASE_WIN_HEIGHT;

		float ratio = (ratioX + ratioY) / 2;

		return val * ratio;
	}

	static int AdaptToWindow(int val)
	{
		float ratioX = static_cast<float>(WINDOW_WIDTH) / BASE_WIN_WIDTH;
		float ratioY = static_cast<float>(WINDOW_HEIGHT) / BASE_WIN_HEIGHT;

		float ratio = (ratioX + ratioY) / 2;

		return static_cast<int>(val * ratio);
	}
}