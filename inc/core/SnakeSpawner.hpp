#ifndef SNAKE_SPAWNER_HPP
#define SNAKE_SPAWNER_HPP

#include "DataStructs.hpp"

class SnakeSpawner
{
public:
    SnakeSpawner() {}
    ~SnakeSpawner() {}

    static void CreateSnakes(struct s_GameData &data, bool multiplayer);
    static void ClearSnakes(struct s_GameData &data);
};


#endif