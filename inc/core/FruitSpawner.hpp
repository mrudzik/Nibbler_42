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

    static bool CreateFruit(struct s_GameData &data);
    static void ClearFruits(struct s_GameData &data);

    static void CheckFruits(struct s_GameData &data);
};


#endif