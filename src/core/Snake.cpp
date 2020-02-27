
#include "Snake.hpp"


Snake::Snake(Tile* startPos)
	: _currPos(startPos)
{
}

Snake::~Snake()
{
}

int Snake::GetPosX() { return _currPos->GetPosX(); }
int Snake::GetPosY() { return _currPos->GetPosY(); }


void Snake::Move(int dir)
{
	if (dir < 0)
		return;
	_currPos = _currPos->GetSide(dir);
}