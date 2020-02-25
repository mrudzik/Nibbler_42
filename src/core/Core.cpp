
#include "Core.hpp"

Core::Core(int x, int y, bool multiplayer)
{
    (void)x;
    (void)y;
    (void)multiplayer;

    CreateMap(x, y);
}

Core::~Core()
{
    ClearMap();
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


void Core::CreateMap(int x_size, int y_size)
{
    for (int y = 0; y < y_size; y++)
    {
        std::vector<Tile*> tempRow;
        for (int x = 0; x < x_size; x++)
        {
            Tile* tempTile = new Tile();
            tempRow.push_back(tempTile);
        }
        _data.tileMap.push_back(tempRow);
    }
}

void Core::ConnectTiles()
{
    // if (_data.tileMap.empty())
    //     return;
    // for (size_t y = 0; y < _data.tileMap.size(); y++)
    // {
    //     if (_data.tileMap.at(y).empty())
    //         continue;
    //     for (size_t x = 0; x < _data.tileMap.at(y).size(); x++)
    //     {
    //         Tile* tempTile = _data.tileMap.at(y).at(x);
    //         if (tempTile == NULL)
    //             continue;
    //         delete tempTile;
    //         tempTile = NULL;
    //     }
    // }
}


void Core::ShowMap()
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
            std::cout << " " << tempTile->GetTileContent();
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


void Core::MakeTurn()
{
    std::cout << "Hi" << std::endl;
    ShowMap();
}

