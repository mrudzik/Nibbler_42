
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


bool Snake::Move(int dir)
{
	// Check if wrong direction
	if (dir < 0)
		dir = lastDir;
	{ // Check if backwards direction
		int tempDir = lastDir + 4;
		// Fix direction to readable by soft
		if (tempDir >= 8) tempDir -= 8;
		// Check direction
		if (dir == tempDir) dir = lastDir;
	}
	// Normal Movement stuff
	lastDir = dir;
	Tile* nextTile = _currPos->GetSide(dir);
 	// Check if bite own tail
	if (OccupiedBySnake(nextTile->GetPosX(), nextTile->GetPosY()))
		return false; // Bite own tail;
	{ // Check on diagonal Movement
		if (dir == 1 || dir == 3 || dir == 5 || dir == 7)
		{// Diagonal Movement checks
			int checkDirs[2] = {dir - 1, dir + 1};
			int matches = 0;
			for (int i = 0; i < 2; i++)
			{
				int tempDir = checkDirs[i];
				if (tempDir < 0) tempDir += 8;
				if (tempDir >= 8) tempDir -= 8;

				Tile* tempTile = _currPos->GetSide(tempDir);
				if (OccupiedBySnake(tempTile->GetPosX(), tempTile->GetPosY()))
					matches++;
			}
			if (matches > 1) return false;
		}
	}

	Tile* newTile = _currPos;
	_tail.insert(_tail.begin(), {newTile});
	if (!growing)
		_tail.pop_back();
	growing = false;
	_currPos = nextTile;
	return true;
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