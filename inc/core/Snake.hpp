#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Tile.hpp"

class Snake
{
private:
	Tile* _currPos;
public:
	Snake(Tile* startPos);
	~Snake();
	int GetPosX();
	int GetPosY();

	void Move(int dir);
};


#endif