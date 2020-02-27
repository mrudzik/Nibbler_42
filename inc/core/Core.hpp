#ifndef CORE_HPP
#define CORE_HPP

#include "Tile.hpp"
#include "Snake.hpp"

#include <iostream>
#include <vector>

struct s_GameData
{
    std::vector<std::vector<Tile*>> tileMap;
    Snake* snake1;
    Snake* snake2;

};



class Core
{
private:
    s_GameData _data;

    // Map Stuff
    void CreateMap(int x, int y);
    void ConnectTiles();
    void ClearMap();
    void ShowMap();

    // Snake Stuff
    void CreateSnakes(bool multiplayer);
    void ClearSnakes();
    
public:
    Core(int x, int y, bool multiplayer);
    ~Core();


    void MakeTurn(int direction);

};


#endif