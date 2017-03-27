#include "CoinManager.h"


CoinManager::CoinManager(Map &m) : MapDisplay(m)
{
	CoinGenerator();
}


CoinManager::~CoinManager()
{
}

void CoinManager::CoinEraser(int posX, int posY) {
	NumCoins--;
	if (NumCoins <= 0) {
		CoinReset();
	}
	else if (MapDisplay.mdpos(posX, posY) == '$') {
		MapDisplay.modify(posX, posY, '.');
	}
}

void CoinManager::CoinReset() {
	for (int i = 0; i < MapDisplay.x; i++) 
		for (int j = 0; j < MapDisplay.y; j++)
			if (MapDisplay.mdpos(i, j) == '$')
				MapDisplay.modify(i, j, '.');

	CoinGenerator();

}
void CoinManager::CoinGenerator() {
	NumCoins = (MapDisplay.x * MapDisplay.y) * (((rand() % 11) + 0.03) / 100);

	int caseX;
	int caseY;

	for (int i = 0; i < NumCoins; i++) {
		caseX = rand() % MapDisplay.x;
		caseY = rand() % MapDisplay.y;
		while (MapDisplay.mdpos(caseX, caseY) != '.') {
			caseX = rand() % MapDisplay.x;
			caseY = rand() % MapDisplay.y;
		}
		MapDisplay.modify(caseX, caseY, '$');
	}
}