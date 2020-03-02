#include "Fruit.hpp"


Fruit::Fruit(int posX, int posY)
    : _posX(posX), _posY(posY)
{
}

Fruit::~Fruit()
{
}

int Fruit::GetPosX() { return _posX; }
int Fruit::GetPosY() { return _posY; }

