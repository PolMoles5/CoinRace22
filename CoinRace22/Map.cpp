#include "Map.h"
#include <iostream>

Map::Map()
{
	x = 5 + rand() % 5;
	y = 5 + rand() % 5;

	md = new char *[x];
	for (int i = 0; i < x; i++){ 
		md[i] = new char[y];
		for (int j = 0; j < y; j++)
			md[i][j] = '.';
	}
		
}
Map::Map(int dificulty)
{
	x = 5 * dificulty + (rand() % ((5 * dificulty * 2) - 5 * dificulty)); 
	y = 5 * dificulty + (rand() % ((5 * dificulty* 2) - 5 * dificulty));

	md = new char *[x];
	for (int i = 0; i < x; i++) {
		md[i] = new char[y];
		for (int j = 0; j < y; j++)
			md[i][j] = '.';
	}
}


Map::~Map()
{	
}

char Map::mdpos(int x, int y) {
	return md[x][y];
}
void Map::modify(int x, int y, char val) {
	md[x][y] = val;
}

std::ostream& operator << (std::ostream & os, const Map &m) {
	for (int i = 0; i < m.x; i++) {	
		for (int j = 0; j < m.y; j++) {
			os << m.md[i][j] << " "; 
		}
		os << std::endl;
	}
	return os;
}