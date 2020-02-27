
#include "Tile.hpp"
#include <iostream>
#include <stdexcept>

Tile::Tile(/* args */)
{
    _tileContent = 0;
    
    for (int i = 0; i < 8; i++)
    {
		Tile* tempTile = NULL;
        _sideTiles.push_back(tempTile);
	}

	
}

Tile::~Tile()
{
}



void Tile::SetTileCoord(int x, int y)
{
	x_Pos = x;
	y_Pos = y;
}

int Tile::GetTileContent() { return _tileContent; }
int Tile::GetPosX() { return x_Pos; }
int Tile::GetPosY() { return y_Pos; }

void Tile::SetSide(TileSide side, Tile* nextTile)
{
	if (side >= _sideTiles.size())
	{
		std::cout << _sideTiles.size() << std::endl;
		throw std::logic_error("Something Wrong with _sideTile size capacity");
	}
	// Assigning Side to lead somewhere
	// NULL by default, if not assigned
	_sideTiles[side] = nextTile;
}

Tile* Tile::GetSide(int dir)
{
	if (dir >= static_cast<int>(_sideTiles.size()))
	{
		std::cout << _sideTiles.size() << std::endl;
		throw std::logic_error("Something Wrong with _sideTile size capacity");
	}
	return _sideTiles[dir];
}