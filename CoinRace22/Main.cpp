#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include "Player.h"
#include "CoinManager.h"
#include "Map.h"
#include "Input.h"

int main()
{
	srand(time(NULL));	

	int difficulty;
	
	std::cout << "+++COIN RACE+++" << std::endl;
	
	std::cout << "Utilitza W A S D per moure el jugador" << std::endl;

	std::cout << "Escull un nivell de dificultat: 1 - Facil   2 - Mitja   3 - Dificil" << std::endl;

	do
	{
		std::cin >> difficulty;

	} while (difficulty <= 0 || difficulty > 3);

	int maxmon = 30 * difficulty;
	int gamemon = maxmon + rand() % maxmon;
	
	Map mapita(difficulty);	
	CoinManager mng(mapita);
	Player jugador(mapita, mng);
	Input::Key key;
	
	clock_t temps;
	temps = clock();

	std::cout << mapita << std::endl;
		

	do {

		key = Input::getKey();

		if (key != Input::Key::NONE) {

			jugador.translate(key);
			system("cls");
			std::cout << mapita << std::endl;
			jugador.ScoreValue();
		}
	} 
	
	while (key != Input::Key::ESC || jugador.score == maxmon);
	
	std::cout << "Fi de la partida" << std::endl;
	
	temps = clock() - temps;
	
	std::cout << "Monedes recollides: " << jugador.score << std::endl;
	std::cout << "Temps total: " << temps / (double)CLOCKS_PER_SEC << " segons" << std::endl;

	system("pause");

	return 0;
}