#include "Player.h"

Player::Player(Map &m, CoinManager &CMng) : md(m), mng(CMng)
{
	posX = rand() % m.x;
	posY = rand() % m.y;
	score = 0;

	while (m.mdpos(posX, posY) != '.') {
		posX = rand() % m.x;
		posY = rand() % m.y;
	}

	m.modify(posX, posY, '@');
}
void Player::translate(Input::Key key) {
	md.modify(posX, posY, '.');

	int auxX = posX;
	int auxY = posY;

	switch (key)
	{
	case Input::Key::W:
		auxX--;
		break;
	case Input::Key::A:
		auxY--;
		break;
	case Input::Key::S:
		auxX++;
		break;
	case Input::Key::D:
		auxY++;
		break;
	default:
		break;

	}
	if (auxX >= 0 && auxX < md.x && auxY >= 0 && auxY < md.y) {
		if (md.mdpos(auxX, auxY) == '$') {
			score++;
			mng.CoinEraser(posX, auxY);
		}
		posX = auxX;
		posY = auxY;
	}

	md.modify(posX, posY, '@');
}
void Player::ScoreValue() {
	std::cout << "Puntuacio: " << score << std::endl;
}

Player::~Player()
{
}