#ifndef CORE_HPP
#define CORE_HPP

#include "Tile.hpp"
#include <iostream>
#include <vector>

struct s_GameData
{
    std::vector<std::vector<Tile*>> tileMap;


};



class Core
{
private:
    s_GameData _data;

    void CreateMap(int x, int y);
    void ConnectTiles();
    void ClearMap();
    void ShowMap();
public:
    Core(int x, int y, bool multiplayer);
    ~Core();


    void MakeTurn();

};


#endif