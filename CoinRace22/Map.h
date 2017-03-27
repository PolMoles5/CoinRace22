#pragma once
#include <iostream>

class Map
{
private:
	char **md;
public:
	int x;
	int y;

	Map();
	Map(int dificulty); 

	~Map();

	char mdpos(int x, int y);
	void modify(int x, int y, char val); 
										 
	friend std::ostream& operator << (std::ostream &out, const Map &m); 
};
