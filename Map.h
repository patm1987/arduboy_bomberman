#ifndef _MAP_H
#define _MAP_H

class Map {
public:
    static const uint8_t EmptyTile = 0;
    static const uint8_t WallTile = 1;
    static const uint8_t PlayerSpawnTile = 2;

    static const int WidthPixels = 128;
    static const int TileWidth = 8;
    static const int Width = WidthPixels / TileWidth;

    static const int HeightPixels = 64;
    static const int TileHeight = 8;
    static const int Height = HeightPixels / TileHeight;

    struct MapConfig{
        const uint8_t* pMapData;
        const uint8_t* pEmptyTile;
        const uint8_t* pWallTile;
        const uint8_t* pPlayerSpawnTile;
    };

    explicit Map(const MapConfig& mapConfig);

    void draw(const Arduboy& arduboy) const;

private:
    MapConfig _mapConfig;
};

#endif//_MAP_H