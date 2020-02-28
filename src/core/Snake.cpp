
#include "Snake.hpp"


Snake::Snake(Tile* startPos, Tile* tail1, Tile* tail2, Tile* tail3)
	: _currPos(startPos)
{
	_tail.push_back(tail1);
	_tail.push_back(tail2);
	_tail.push_back(tail3);
}

Snake::~Snake()
{
}

int Snake::GetPosX() { return _currPos->GetPosX(); }
int Snake::GetPosY() { return _currPos->GetPosY(); }


void Snake::Move(int dir, bool growing)
{
	if (dir < 0)
		return;
	lastDir = dir;

	Tile* newTile = _currPos;
	_tail.insert(_tail.begin(), {newTile});
	if (!growing)
		_tail.pop_back();
	
	_currPos = _currPos->GetSide(dir);
}

void Snake::MarkOccupiedTiles(std::vector<std::vector<int>> &result)
{
	result[GetPosY()][GetPosX()] = 1;
	for (size_t i = 0; i < _tail.size(); i++)
	{
		Tile* tempTile = _tail[i];
		result[tempTile->GetPosY()][tempTile->GetPosX()] = 2;
	}
}

bool Snake::OccupiedBySnake(int x, int y)
{
	// Check Snake Head
	if (GetPosX() == x && GetPosY() == y)
		return true;
	// Check Snake Tail
	for (size_t i = 0; i < _tail.size(); i++)
	{
		if (_tail.at(i)->GetPosX() == x && _tail.at(i)->GetPosY() == y)
			return true;
	}
	return false;
}