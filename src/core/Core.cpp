
#include "Core.hpp"

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






struct s_CoreOutput Core::MakeTurn(s_CoreInput input)
{
    struct s_CoreOutput outResult;

    if (input.direction < 0)
    {
        input.direction = _data.snake1->lastDir;
    }

    // Check if snake ate any fruits
    FruitSpawner::CheckFruits(_data);
    // Spawn Fruits if all eaten
    if (_data.fruits.empty())
        outResult.win = !FruitSpawner::CreateFruit(_data);
    outResult.lose = !_data.snake1->Move(input.direction);

    MapBuilder::SliceMap(_data, outResult);
    // MapBuilder::ShowMap(_data);
    return outResult;
}

