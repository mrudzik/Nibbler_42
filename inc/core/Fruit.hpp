#ifndef FRUIT_HPP
#define FRUIT_HPP


class Fruit
{
private:
    int _posX;
    int _posY;
public:
    Fruit(int posX, int posY);
    ~Fruit();

    int GetPosX();
    int GetPosY();
};

Fruit::Fruit(int posX, int posY)
{
}

Fruit::~Fruit()
{
}

int Fruit::GetPosX() { return _posX; }
int Fruit::GetPosY() { return _posY; }


#endif