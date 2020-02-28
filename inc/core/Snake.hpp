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
	int lastDir = -1;
	
	Snake(Tile* startPos, Tile* tail1, Tile* tail2, Tile* tail3);
	~Snake();
	int GetPosX();
	int GetPosY();

	void MarkOccupiedTiles(std::vector<std::vector<int>> &result);
	void Move(int dir, bool growing);

	bool OccupiedBySnake(int x, int y);
};


#endif