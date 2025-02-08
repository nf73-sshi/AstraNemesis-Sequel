#include "main.h"
#include "GameManager.h"

int main()
{
	GameManager pGameManager;
	pGameManager.GetInstance()->RunGame();

	return 0;
}
 