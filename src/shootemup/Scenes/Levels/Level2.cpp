#include "Level2.h"
#include "../../Important/res.h"
#include "../../HealthMana/HealthBar.h"
#include "../../Important/AssetManager.h"
#include "../../Important/Debug.h"

void Level2::Init()
{
	Level::Init();

	infinite = true;

	auto am = AssetManager::Get();

	am->PlayMusic("Dynamic Music1");
}