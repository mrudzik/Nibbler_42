#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Tile.hpp"
#include <vector>

class Snake
{
private:
	Tile* _currPos;
	std::vector<Tile*> _tail;

public:
	int lastDir = 2;
	bool growing = false;

	Snake(Tile* startPos, Tile* tail1, Tile* tail2, Tile* tail3);
	~Snake();
	int GetPosX();
	int GetPosY();

	void MarkOccupiedTiles(std::vector<std::vector<int>> &result);
	bool Move(int dir);

	bool OccupiedBySnake(int x, int y);
};


#endif