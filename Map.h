#ifndef _MAP_H
#define _MAP_H

class Map {
public:
    enum class TileId {
        Empty,
        Wall,
        PlayerSpawn
    };

    static const int WidthPixels = 128;
    static const int TileWidth = 8;
    static const int Width = WidthPixels / TileWidth;

    static const int HeightPixels = 64;
    static const int TileHeight = 8;
    static const int Height = HeightPixels / TileHeight;

    struct MapConfig{
        const uint8_t* pMapData = nullptr;
        const uint8_t* pEmptyTile = nullptr;
        const uint8_t* pWallTile = nullptr;
        const uint8_t* pPlayerSpawnTile = nullptr;
    };

    explicit Map(const MapConfig& mapConfig);

private:
    MapConfig _mapConfig;
};

#endif//_MAP_H