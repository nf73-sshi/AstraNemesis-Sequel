#pragma once

class GameManager
{
	static GameManager* mInstance;

public:
	static GameManager* GetInstance();
	
	void RunGame();



};

