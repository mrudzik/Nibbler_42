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


struct s_CoreInput
{
    int direction = -1;
};

struct s_CoreOutput
{
    // Tiles to Draw in layers
    std::vector<std::vector<int>> mapLayer;
    std::vector<std::vector<int>> snakeLayer;
    std::vector<std::vector<int>> fruitLayer;

    bool win = false;
    bool lose = false;

};


#endif