
#include "Core.hpp"

#include "MapBuilder.hpp"
#include "SnakeSpawner.hpp"
#include "FruitSpawner.hpp"

Core::Core(int x, int y, bool multiplayer)
{
    MapBuilder::CreateMap(_data, x, y);
    MapBuilder::ConnectTiles(_data);

    SnakeSpawner::CreateSnakes(_data, multiplayer);
    CreateFruit();
}

Core::~Core()
{
    MapBuilder::ClearMap(_data);
    SnakeSpawner::ClearSnakes(_data);
    FruitSpawner::ClearFruit(_data);
}






void Core::MakeTurn(int direction)
{
    if (direction == -2)
    {
        direction = _data.snake1->lastDir;
        _data.snake1->Move(direction, true);
    }
    else if (direction < 0)
    {
        direction = _data.snake1->lastDir;
        _data.snake1->Move(direction, false);
    }
    else
        _data.snake1->Move(direction, false);
    // If Fruit
    //      Occupied by Snake
    //          Spawn Fruit


    std::cout << "Hi" << std::endl;
    MapBuilder::ShowMap(_data);
}

