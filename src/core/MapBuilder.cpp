#include "MapBuilder.hpp"


void MapBuilder::ClearMap(struct s_GameData &data)
{// Clear Map
    if (data.tileMap.empty())
        return;
    for (size_t y = 0; y < data.tileMap.size(); y++)
    {
        if (data.tileMap.at(y).empty())
            continue;
        for (size_t x = 0; x < data.tileMap.at(y).size(); x++)
        {
            Tile* tempTile = data.tileMap.at(y).at(x);
            if (tempTile == NULL)
                continue;
            delete tempTile;
            tempTile = NULL;
        }
    }
}

void MapBuilder::CreateMap(struct s_GameData &data, int x_size, int y_size)
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
        data.tileMap.push_back(tempRow);
    }
}

void MapBuilder::ConnectTiles(struct s_GameData &data)
{
    if (data.tileMap.empty())
        return;
    for (size_t y = 0; y < data.tileMap.size(); y++)
    {
        if (data.tileMap.at(y).empty())
            continue;
        for (size_t x = 0; x < data.tileMap.at(y).size(); x++)
        {
            Tile* tempTile = data.tileMap.at(y).at(x);
            
            // Normal Connections
            if (y > 0)
            {// All Upper Sides
                tempTile->SetSide(e_Up, data.tileMap.at(y - 1).at(x));
                if (x > 0)
                    tempTile->SetSide(e_UpLeft, data.tileMap.at(y - 1).at(x - 1));
                if (x < data.tileMap.at(y).size() - 1)
                    tempTile->SetSide(e_UpRight, data.tileMap.at(y - 1).at(x + 1));
            }
            if (y < data.tileMap.size() - 1)
            {// All Down Sides
                tempTile->SetSide(e_Down, data.tileMap.at(y + 1).at(x));
                if (x > 0)
                    tempTile->SetSide(e_DownLeft, data.tileMap.at(y + 1).at(x - 1));
                if (x < data.tileMap.at(y).size() - 1)
                    tempTile->SetSide(e_DownRight, data.tileMap.at(y + 1).at(x + 1));
            }
            // Left and Right
            if (x > 0)
                tempTile->SetSide(e_Left, data.tileMap.at(y).at(x - 1));
            if (x < data.tileMap.at(y).size() - 1)
                tempTile->SetSide(e_Right, data.tileMap.at(y).at(x + 1));

            // Warp Connections
            if (y == 0)
            { // Upper border
                int tempY = data.tileMap.size() - 1;
                // Only Up
                tempTile->SetSide(e_Up, data.tileMap.at(tempY).at(x));

                if (x > 0) // Up Left Normal
                    tempTile->SetSide(e_UpLeft, data.tileMap.at(tempY).at(x - 1));
                else if (x == 0) // Up Left Corner
                    tempTile->SetSide(e_UpLeft, data.tileMap.at(tempY).at(data.tileMap.at(tempY).size() - 1));

                if (x < data.tileMap.at(y).size() - 1) // Up Right Normal
                    tempTile->SetSide(e_UpRight, data.tileMap.at(tempY).at(x + 1));
                else if (x == data.tileMap.at(y).size() - 1) // Up Right Corner
                    tempTile->SetSide(e_UpRight, data.tileMap.at(tempY).at(0));
            }

            if (y == data.tileMap.size() - 1)
            { // Down border
                int tempY = 0;
                // Only Down
                tempTile->SetSide(e_Down, data.tileMap.at(tempY).at(x));

                if (x > 0) // Down Left Normal
                    tempTile->SetSide(e_DownLeft, data.tileMap.at(tempY).at(x - 1));
                else if (x == 0) // Down Left Corner
                    tempTile->SetSide(e_DownLeft, data.tileMap.at(tempY).at(data.tileMap.at(tempY).size() - 1));

                if (x < data.tileMap.at(y).size() - 1) // Down Right Normal
                    tempTile->SetSide(e_DownRight, data.tileMap.at(tempY).at(x + 1));
                else if (x == data.tileMap.at(y).size() - 1) // Down Right Corner
                    tempTile->SetSide(e_DownRight, data.tileMap.at(tempY).at(0));
            }

        
            if (x == 0)
            {// Left Border
                // Only Left
                tempTile->SetSide(e_Left, data.tileMap.at(y).at(data.tileMap.at(y).size() - 1));
                if (y > 0) // Not Upper Border (to avoid redefinition of corner UpLeft)
                {// For UpLeft
                    tempTile->SetSide(e_UpLeft, data.tileMap.at(y - 1).at(data.tileMap.at(y - 1).size() - 1));
                }
                if (y < data.tileMap.size() - 1) // Not Down Border
                {// For DownLeft
                    tempTile->SetSide(e_DownLeft, data.tileMap.at(y + 1).at(data.tileMap.at(y + 1).size() - 1));
                }
            }
            if (x == data.tileMap.at(y).size() - 1)
            {// Right Border
                // Only Right
                tempTile->SetSide(e_Right, data.tileMap.at(y).at(0));
                if (y > 0) // Not Upper Border (to avoid redefinition of corner UpLeft)
                {// For UpRight
                    tempTile->SetSide(e_UpRight, data.tileMap.at(y - 1).at(0));
                }
                if (y < data.tileMap.size() - 1) // Not Down Border
                {// For DownRight
                    tempTile->SetSide(e_DownRight, data.tileMap.at(y + 1).at(0));
                }
            }

        }
    }
}


void MapBuilder::ShowMap(const struct s_CoreOutput output)
{
    std::vector<std::vector<int>> result;

    // This will Draw map with snake on console
    for (size_t y = 0; y < output.mapLayer.size(); y++)
    {
        for (size_t x = 0; x < output.mapLayer.at(y).size(); x++)
        {
            std::cout << " ";
            if (output.snakeLayer[y][x] != 0)
                std::cout << output.snakeLayer[y][x];
            else if (output.fruitLayer[y][x] != 0)
                std::cout << output.fruitLayer[y][x];
            else
            {
                int result = output.mapLayer[y][x];
                if (result == 0)
                    std::cout << ".";
                else
                    std::cout << result;
            }     
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void MapBuilder::SliceMap(const struct s_GameData &data, struct s_CoreOutput &output)
{
    std::vector<std::vector<int>> slice;
    // Map Layer
    output.mapLayer.clear();
    for (size_t y = 0; y < data.tileMap.size(); y++)
    {
        std::vector<int> verRow;
        std::vector<int> emptyLine;
        for (size_t x = 0; x < data.tileMap.at(y).size(); x++)
        {
            verRow.push_back(data.tileMap.at(y).at(x)->GetTileContent());
            emptyLine.push_back(0);
        }
        output.mapLayer.push_back(verRow);
        slice.push_back(emptyLine);
    }

    // Snake Layer
    output.snakeLayer.clear();
    output.snakeLayer = slice;
    data.snake1->MarkOccupiedTiles(output.snakeLayer);

    // Fruit Layer
    output.fruitLayer.clear();
    output.fruitLayer = slice;
    for (size_t i = 0; i < data.fruits.size(); i++)
    {
        Fruit* tempFruit = data.fruits[i];
        if (tempFruit == NULL)
            continue;
        output.fruitLayer[tempFruit->GetPosY()][tempFruit->GetPosX()] = 5;
    }
}
