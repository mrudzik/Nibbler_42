#ifndef FRUIT_SPAWNER_HPP
#define FRUIT_SPAWNER_HPP

#include "Fruit.hpp"
#include "DataStructs.hpp"

class FruitSpawner
{
private:
    /* data */
public:
    FruitSpawner(/* args */) {}
    ~FruitSpawner() {}

    static void CreateFruit(struct s_GameData);
    static void ClearFruit(struct s_GameData);
};



#endif