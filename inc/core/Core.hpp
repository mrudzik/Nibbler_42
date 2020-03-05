#ifndef CORE_HPP
#define CORE_HPP

#include "DataStructs.hpp"

#include "MapBuilder.hpp"
#include "SnakeSpawner.hpp"
#include "FruitSpawner.hpp"

#include <iostream>
#include <vector>

class Core
{
private:
    s_GameData _data;

    // // Map Stuff
    // void CreateMap(int x, int y);
    // void ConnectTiles();
    // void ClearMap();
    // void ShowMap();

    // // Snake Stuff
    // void CreateSnakes(bool multiplayer);
    // void ClearSnakes();
    
    // Fruit Stuff
    // void CreateFruit();

public:
    Core(int x, int y, bool multiplayer);
    ~Core();


    struct s_CoreOutput MakeTurn(s_CoreInput input);

};


#endif