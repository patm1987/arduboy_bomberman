#ifndef _MAP_H
#define _MAP_H

#include "Vec2i.h"

/**
 * Defines a Map on which we can play Bomberman
 */
class Map
{
  public:
    //! A tile that we can walk on
    static const uint8_t EmptyTile = 0;

    //! A tile representing a wall
    static const uint8_t WallTile = 1;

    //! The tile the player spawns at
    static const uint8_t PlayerSpawnTile = 2;

    //! Width of the map in pixels (the screen size of Arduboy)
    static const int WidthPixels = 128;

    //! Width of a tile in the map
    static const int TileWidth = 8;

    //! The width of the map in tiles
    static const int Width = WidthPixels / TileWidth;

    //! The height of the map in pixels (the screen size of Arduboy)
    static const int HeightPixels = 64;

    //! The height of a tile in the map
    static const int TileHeight = 8;

    //! The height of the map in tiles
    static const int Height = HeightPixels / TileHeight;

    /*!
     * Converts a position of the map in tiles to a position on the map in pixels
     * @param mapPosition the position on the map to convert
     * @return the position in pixels
     */
    static constexpr Vec2i mapPositionToPixelPosition(Vec2i mapPosition)
    {
        return Vec2i(
            mapPosition.X * TileWidth,
            mapPosition.Y * TileHeight);
    }

    /*!
     * Struct used to create a map, all the parameters to configure
     */
    struct MapConfig
    {
        const uint8_t *pMapData;
        const uint8_t *pEmptyTile;
        const uint8_t *pWallTile;
        const uint8_t *pPlayerSpawnTile;
    };

    /*!
     * Creates a map given a configuration
     * @param mapConfig the map configuration
     */
    explicit Map(const MapConfig &mapConfig);

    /*!
     * Draws the map using the provided arduboy library
     * @param the library used for drawing
     */
    void draw(Arduboy &arduboy) const;

    /*!
     * Gets the start position for the player
     * @return the player's start position
     */
    Vec2i getPlayerSpawnPosition() const;

    /*!
     * Determines if a space on the map is empty/can be moved onto
     * @param tilePosition the space on the map to check
     * @return true if the given tile position is empty
     */
    bool isSpaceEmpty(const Vec2i &tilePosition) const;

  private:
    /*!
     * Given some offset into map memory, tells you the tile there
     * @param offset the offset into map memory
     * @return the tile at the offset
     */
    uint8_t getTileAtOffset(ptrdiff_t offset) const;

    MapConfig _mapConfig;
};

inline uint8_t Map::getTileAtOffset(ptrdiff_t offset) const
{
    return pgm_read_word_near(_mapConfig.pMapData + offset);
}

inline bool Map::isSpaceEmpty(const Vec2i &tilePosition) const
{
    if (tilePosition.X < 0 || tilePosition.Y < 0 || tilePosition.X >= Width || tilePosition.Y >= Height)
    {
        return false;
    }
    uint8_t tile = getTileAtOffset(tilePosition.Y * Width + tilePosition.X);
    return tile != WallTile;
}

#endif //_MAP_H