
#include "Core.hpp"

#include "MapBuilder.hpp"
#include "SnakeSpawner.hpp"
#include "FruitSpawner.hpp"

Core::Core(int x, int y, bool multiplayer)
{
    MapBuilder::CreateMap(_data, x, y);
    MapBuilder::ConnectTiles(_data);

    SnakeSpawner::CreateSnakes(_data, multiplayer);
    FruitSpawner::CreateFruit(_data);
}

Core::~Core()
{
    MapBuilder::ClearMap(_data);
    SnakeSpawner::ClearSnakes(_data);
    FruitSpawner::ClearFruits(_data);
}






void Core::MakeTurn(int direction)
{
    bool win = false;
    bool lose = false;

    if (direction < 0)
    {
        direction = _data.snake1->lastDir;
    }

    // Check if snake ate any fruits
    FruitSpawner::CheckFruits(_data);
    // Spawn Fruits if all eaten
    if (_data.fruits.empty())
        win = !FruitSpawner::CreateFruit(_data);
    lose = !_data.snake1->Move(direction);

    // Spawn Fruit here
    MapBuilder::ShowMap(_data);

    if (win)
        throw std::logic_error("Win");
    if (lose)
        throw std::logic_error("Lose");
}

