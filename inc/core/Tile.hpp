#ifndef TILE_HPP
#define TILE_HPP

#include <vector>

class Tile
{
private:
    int _tileContent;
    std::vector<Tile*> _sideTiles;

public:
    Tile(/* args */);
    ~Tile();

    int GetTileContent();
};



#endif