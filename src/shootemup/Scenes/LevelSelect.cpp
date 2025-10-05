#include "LevelSelect.h"
#include "../Important/res.h"

constexpr int MAXLEVELS = 28;
constexpr int COLUMNS = 7;
constexpr int LINES = 4;

Lvl2Button::Lvl2Button()
{
	CreateSprite("lvl2Button", 0, 0, 120, 120);
}

void Lvl2Button::Update(float delta)
{
	Button::Update(delta);

	if (Button::IsClicked())
		GameManager::Get()->GetCurrentSceneManager().ChangeScene("Lvl2");
}

Lvl1Button::Lvl1Button() : Button()
{
	CreateSprite("lvl1Button", 0, 0, 120, 120);
}

void Lvl1Button::Update(float delta)
{
	Button::Update(delta); 

	if (Button::IsClicked())
		GameManager::Get()->GetCurrentSceneManager().ChangeScene("Lvl1");

}



LevelSelect::~LevelSelect()
{
}

void LevelSelect::Init()
{
	Background* pBG = new Background();

	std::vector<Button*> lvlButtons;
	
	lvlButtons.push_back(new Lvl1Button());
	lvlButtons.push_back(new Lvl2Button());

	int size = lvlButtons.size(); // Amount of Buttons

	int index = 0;

	for (int j = 0; j < LINES; ++j)
	{
		if (index >= size)
			break;

		for (int i = 0; i < COLUMNS; ++i)
		{
			if (index >= size)
				break;

			lvlButtons[index]->setPosition(240 * (i +1), 140 + j * 240); // 240 = 2 * size of button Sprite
			addEntity(lvlButtons[index]);
			index++;
		}
	}

	BackButton* pBack = new BackButton("Menu");
	pBack->setPosition(WINDOW_WIDTH - 100, WINDOW_HEIGHT - 50);

	addEntity(pBG);
	addEntity(pBack);

	lvlButtons.clear();
}

void LevelSelect::Update(float delta)
{
	mousePos = sf::Mouse::getPosition();

	Scene::Update(delta);
}
