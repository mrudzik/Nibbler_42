
#include "Core.hpp"

Core::Core(int x, int y, bool multiplayer)
{
    CreateMap(x, y);
    ConnectTiles();

    CreateSnakes(multiplayer);
    CreateFruit();
}

Core::~Core()
{
    ClearMap();
    ClearSnakes();
}


void Core::ClearMap()
{// Clear Map
    if (_data.tileMap.empty())
        return;
    for (size_t y = 0; y < _data.tileMap.size(); y++)
    {
        if (_data.tileMap.at(y).empty())
            continue;
        for (size_t x = 0; x < _data.tileMap.at(y).size(); x++)
        {
            Tile* tempTile = _data.tileMap.at(y).at(x);
            if (tempTile == NULL)
                continue;
            delete tempTile;
            tempTile = NULL;
        }
    }
}

void Core::ClearSnakes()
{
    if (_data.snake1 != NULL)
    {
        delete _data.snake1;
        _data.snake1 = NULL;
    }
    if (_data.snake2 != NULL)
    {
        delete _data.snake2;
        _data.snake2 = NULL;
    }
}













void Core::CreateMap(int x_size, int y_size)
{
    for (int y = 0; y < y_size; y++)
    {
        std::vector<Tile*> tempRow;
        for (int x = 0; x < x_size; x++)
        {
            Tile* tempTile = new Tile();
            tempTile->SetTileCoord(x, y);

            tempRow.push_back(tempTile);
        }
        _data.tileMap.push_back(tempRow);
    }
}

void Core::ConnectTiles()
{
    if (_data.tileMap.empty())
        return;
    for (size_t y = 0; y < _data.tileMap.size(); y++)
    {
        if (_data.tileMap.at(y).empty())
            continue;
        for (size_t x = 0; x < _data.tileMap.at(y).size(); x++)
        {
            Tile* tempTile = _data.tileMap.at(y).at(x);
            
            // Normal Connections
            if (y > 0)
            {// All Upper Sides
                tempTile->SetSide(e_Up, _data.tileMap.at(y - 1).at(x));
                if (x > 0)
                    tempTile->SetSide(e_UpLeft, _data.tileMap.at(y - 1).at(x - 1));
                if (x < _data.tileMap.at(y).size() - 1)
                    tempTile->SetSide(e_UpRight, _data.tileMap.at(y - 1).at(x + 1));
            }
            if (y < _data.tileMap.size() - 1)
            {// All Down Sides
                tempTile->SetSide(e_Down, _data.tileMap.at(y + 1).at(x));
                if (x > 0)
                    tempTile->SetSide(e_DownLeft, _data.tileMap.at(y + 1).at(x - 1));
                if (x < _data.tileMap.at(y).size() - 1)
                    tempTile->SetSide(e_DownRight, _data.tileMap.at(y + 1).at(x + 1));
            }
            // Left and Right
            if (x > 0)
                tempTile->SetSide(e_Left, _data.tileMap.at(y).at(x - 1));
            if (x < _data.tileMap.at(y).size() - 1)
                tempTile->SetSide(e_Right, _data.tileMap.at(y).at(x + 1));

            // Warp Connections
            if (y == 0)
            { // Upper border
                int tempY = _data.tileMap.size() - 1;
                // Only Up
                tempTile->SetSide(e_Up, _data.tileMap.at(tempY).at(x));

                if (x > 0) // Up Left Normal
                    tempTile->SetSide(e_UpLeft, _data.tileMap.at(tempY).at(x - 1));
                else if (x == 0) // Up Left Corner
                    tempTile->SetSide(e_UpLeft, _data.tileMap.at(tempY).at(_data.tileMap.at(tempY).size() - 1));

                if (x < _data.tileMap.at(y).size() - 1) // Up Right Normal
                    tempTile->SetSide(e_UpRight, _data.tileMap.at(tempY).at(x + 1));
                else if (x == _data.tileMap.at(y).size() - 1) // Up Right Corner
                    tempTile->SetSide(e_UpRight, _data.tileMap.at(tempY).at(0));
            }

            if (y == _data.tileMap.size() - 1)
            { // Down border
                int tempY = 0;
                // Only Down
                tempTile->SetSide(e_Down, _data.tileMap.at(tempY).at(x));

                if (x > 0) // Down Left Normal
                    tempTile->SetSide(e_DownLeft, _data.tileMap.at(tempY).at(x - 1));
                else if (x == 0) // Down Left Corner
                    tempTile->SetSide(e_DownLeft, _data.tileMap.at(tempY).at(_data.tileMap.at(tempY).size() - 1));

                if (x < _data.tileMap.at(y).size() - 1) // Down Right Normal
                    tempTile->SetSide(e_DownRight, _data.tileMap.at(tempY).at(x + 1));
                else if (x == _data.tileMap.at(y).size() - 1) // Down Right Corner
                    tempTile->SetSide(e_DownRight, _data.tileMap.at(tempY).at(0));
            }

        
            if (x == 0)
            {// Left Border
                // Only Left
                tempTile->SetSide(e_Left, _data.tileMap.at(y).at(_data.tileMap.at(y).size() - 1));
                if (y > 0) // Not Upper Border (to avoid redefinition of corner UpLeft)
                {// For UpLeft
                    tempTile->SetSide(e_UpLeft, _data.tileMap.at(y - 1).at(_data.tileMap.at(y - 1).size() - 1));
                }
                if (y < _data.tileMap.size() - 1) // Not Down Border
                {// For DownLeft
                    tempTile->SetSide(e_DownLeft, _data.tileMap.at(y + 1).at(_data.tileMap.at(y + 1).size() - 1));
                }
            }
            if (x == _data.tileMap.at(y).size() - 1)
            {// Right Border
                // Only Right
                tempTile->SetSide(e_Right, _data.tileMap.at(y).at(0));
                if (y > 0) // Not Upper Border (to avoid redefinition of corner UpLeft)
                {// For UpRight
                    tempTile->SetSide(e_UpRight, _data.tileMap.at(y - 1).at(0));
                }
                if (y < _data.tileMap.size() - 1) // Not Down Border
                {// For DownRight
                    tempTile->SetSide(e_DownRight, _data.tileMap.at(y + 1).at(0));
                }
            }

        }
    }
}


void Core::ShowMap()
{
    std::vector<std::vector<int>> result;

    // This will translate _data map on result;
    if (_data.tileMap.empty())
        return;
    for (size_t y = 0; y < _data.tileMap.size(); y++)
    {
        std::vector<int> verRow;
        for (size_t x = 0; x < _data.tileMap.at(y).size(); x++)
        {
            verRow.push_back(_data.tileMap.at(y).at(x)->GetTileContent());
        }
        result.push_back(verRow);
    }


    // This will draw snake on result

    _data.snake1->MarkOccupiedTiles(result);





    // This will Draw map with snake on console
    for (size_t y = 0; y < result.size(); y++)
    {
        for (size_t x = 0; x < result.at(y).size(); x++)
        {
            std::cout << " " << result.at(y).at(x);
        }
        std::cout << "\n";
    }
    std::cout << std::endl;

}











void Core::CreateSnakes(bool multiplayer)
{
    (void)multiplayer;
    

    int y = _data.tileMap.size() / 2;
    int x = _data.tileMap.at(y).size() / 2;

    _data.snake1 = new Snake(
            _data.tileMap.at(y).at(x),
            _data.tileMap.at(y - 1).at(x),
            _data.tileMap.at(y - 1).at(x - 1),
            _data.tileMap.at(y).at(x - 1));


    _data.snake2 = NULL;
}















void Core::CreateFruit()
{
    // int yNew = rand() % _data.tileMap.size();
    // int xNew = rand() % _data.tileMap.at(yNew).size();

    // if (!_data.snake1->OccupiedBySnake(xNew, yNew))
    // {

    // }

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
    ShowMap();
}

