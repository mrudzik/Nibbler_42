#ifndef MAP_BUILDER_HPP
#define MAP_BUILDER_HPP

#include <iostream>
#include <vector>
#include "DataStructs.hpp"

class MapBuilder
{
public:
    MapBuilder() {}
    ~MapBuilder() {}

    // Map Stuff
    static void CreateMap(struct s_GameData &data, int x, int y);
    static void ConnectTiles(struct s_GameData &data);
    static void ClearMap(struct s_GameData &data);
    static void ShowMap(const struct s_CoreOutput output);
    static void SliceMap(const struct s_GameData &data, struct s_CoreOutput &output);

};



#endif