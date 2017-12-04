#ifndef _MAP_H
#define _MAP_H

#include "Vec2i.h"

class Map
{
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

    static constexpr Vec2i mapPositionToPixelPosition(Vec2i mapPosition)
    {
        return Vec2i(
            mapPosition.X * TileWidth,
            mapPosition.Y * TileHeight);
    }

    struct MapConfig
    {
        const uint8_t *pMapData;
        const uint8_t *pEmptyTile;
        const uint8_t *pWallTile;
        const uint8_t *pPlayerSpawnTile;
    };

    explicit Map(const MapConfig &mapConfig);

    void draw(const Arduboy &arduboy) const;
    Vec2i getPlayerSpawnPosition() const;

  private:
    uint8_t getTileAtOffset(ptrdiff_t offset) const;

    MapConfig _mapConfig;
};

inline uint8_t Map::getTileAtOffset(ptrdiff_t offset) const {
    return pgm_read_word_near(_mapConfig.pMapData + offset);
}

#endif //_MAP_H