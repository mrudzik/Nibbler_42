#ifndef DATA_STRUCTS_HPP
#define DATA_STRUCTS_HPP

#include <vector>
#include "Snake.hpp"
#include "Tile.hpp"
#include "Fruit.hpp"

struct s_GameData
{
    std::vector<std::vector<Tile*>> tileMap;
    
    Snake* snake1 = NULL;
    Snake* snake2 = NULL;

    std::vector<Fruit*> fruits;
};




#endif