#include "SnakeSpawner.hpp"


void SnakeSpawner::ClearSnakes(struct s_GameData &data)
{
    if (data.snake1 != NULL)
    {
        delete data.snake1;
        data.snake1 = NULL;
    }
    if (data.snake2 != NULL)
    {
        delete data.snake2;
        data.snake2 = NULL;
    }
}


void SnakeSpawner::CreateSnakes(struct s_GameData &data, bool multiplayer)
{
    (void)multiplayer;
    

    int y = data.tileMap.size() / 2;
    int x = data.tileMap.at(y).size() / 2;

    data.snake1 = new Snake(
            data.tileMap.at(y).at(x),
            data.tileMap.at(y - 1).at(x),
            data.tileMap.at(y - 1).at(x - 1),
            data.tileMap.at(y).at(x - 1));
            
    data.snake2 = NULL;
}
