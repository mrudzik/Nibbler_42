#ifndef TILE_HPP
#define TILE_HPP


// Side tip
// 7 0 1
// 6 x 2
// 5 4 3

enum TileSide
{// Do not change arrangment
// If need to change please specify
// their num (example "e_Up = 0")
    e_Up,
    e_UpRight,
    e_Right,
    e_DownRight,
    e_Down,
    e_DownLeft,
    e_Left,
    e_UpLeft
};

#include <vector>

class Tile
{
private:
    int _tileContent;
    std::vector<Tile*> _sideTiles;

    int x_Pos = -1;
    int y_Pos = -1;

public:
    Tile(/* args */);
    ~Tile();

    int GetTileContent();

    void SetTileCoord(int x, int y);
    int GetPosX();
    int GetPosY();
    

    void SetSide(TileSide side, Tile* nextTile);
    Tile* GetSide(int dir);
};



#endif