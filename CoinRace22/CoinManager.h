#pragma once
#include "Map.h"

class CoinManager
{
private:
	void CoinGenerator();

public:
	int NumCoins;
	Map &MapDisplay;

	CoinManager(Map &m);
	~CoinManager();

	void CoinEraser(int posX, int posY); 
	void CoinReset();
};