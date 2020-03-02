
#include "FruitSpawner.hpp"
#include <stdexcept>

bool FruitSpawner::CreateFruit(struct s_GameData &data)
{
    // This will store coordinates of clear tiles;
    std::vector<int> xCord;
    std::vector<int> yCord;

    // Check every map tile is it clear
    for (size_t y = 0; y < data.tileMap.size(); y++)
    {
        for (size_t x = 0; x < data.tileMap.at(y).size(); x++)
        {
            Tile* tempTile = data.tileMap.at(y).at(x);
            if (tempTile == NULL)
                throw std::logic_error("Temp map tile is NULL");
            
            // Check for map passage
            if (tempTile->GetTileContent() != 0)
                continue;
            // Check for snake presence
            if (data.snake1->OccupiedBySnake(tempTile->GetPosX(), tempTile->GetPosY()))
                continue;
            // If everything is ok and you are here than save this coords;
            xCord.push_back(tempTile->GetPosX());
            yCord.push_back(tempTile->GetPosY());
        }
    }

    // Now select random coords;
    size_t posCount = xCord.size();
    if (posCount > 2)
    {// If we still have place where to spawn fruit
        int random = rand() % posCount;
        int posX = xCord.at(random);
        int posY = yCord.at(random);

        Fruit* newFruit = new Fruit(posX, posY);
        data.fruits.push_back(newFruit);
        return true;
    }
    return false;    
}

void FruitSpawner::ClearFruits(struct s_GameData &data)
{
    for (size_t i = 0; i < data.fruits.size(); i++)
    {
        Fruit* tempObj = data.fruits.at(i);
        if (tempObj != NULL)
        {
            delete tempObj;
            tempObj = NULL;
        }
    }
    data.fruits.clear();
}

void FruitSpawner::CheckFruits(struct s_GameData &data)
{
    // This will help clear all eaten fruits from memory
    std::vector<Fruit*> stillAlive;
    
    for (size_t fruitCount = 0; fruitCount < data.fruits.size(); fruitCount++)
    {
        Fruit* tempFruit = data.fruits.at(fruitCount);
        if (tempFruit == NULL)
            continue;
        if (data.snake1->GetPosX() == tempFruit->GetPosX()
            && data.snake1->GetPosY() == tempFruit->GetPosY())
        {// When head meets with fruit
            data.snake1->growing = true;
            delete tempFruit;
            data.fruits[fruitCount] = NULL;
            continue;
        }
        stillAlive.push_back(tempFruit);
    }

    data.fruits = stillAlive;
}