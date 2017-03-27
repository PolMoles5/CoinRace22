#pragma once
#include <iostream>
#include "Input.h"
#include "Map.h"
#include "CoinManager.h"

class Player
{
public:
	int posX;
	int posY;
	Map &md;
	CoinManager &mng;

	int score;

	Player(Map &m, CoinManager &CMng);
	~Player();

	void translate(Input::Key key); 
	void ScoreValue();
};