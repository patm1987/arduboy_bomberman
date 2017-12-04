#include "stdafx.h"

#include "Map.h"

Map::Map(const MapConfig &mapConfig)
{
    memcpy(&_mapConfig, &mapConfig, sizeof(MapConfig));
}

void Map::draw(const Arduboy &arduboy) const
{
    int mapIndex = 0;
    arduboy.drawRect(0, 0, WidthPixels, HeightPixels, BLACK);
    for (int y = 0; y < HeightPixels; y += TileHeight)
    {
        for (int x = 0; x < WidthPixels; x += TileWidth, mapIndex++)
        {
            uint8_t tile = getTileAtOffset(mapIndex);
            const uint8_t *pBitmap;
            switch (tile)
            {
            default:
            case EmptyTile:
                pBitmap = _mapConfig.pEmptyTile;
                break;
            case WallTile:
                pBitmap = _mapConfig.pWallTile;
                break;
            case PlayerSpawnTile:
                pBitmap = _mapConfig.pPlayerSpawnTile;
                break;
            }
            arduboy.drawBitmap(x, y, pBitmap, TileWidth, TileHeight, WHITE);
        }
        Serial.println();
    }
}

Vec2i Map::getPlayerSpawnPosition() const 
{
    Vec2i position;
    int offset = 0;
    for(;position.Y < Height; position.Y++) 
    {
        for(;position.X < Width; position.X++, offset++)
        {
            if(getTileAtOffset(offset) == PlayerSpawnTile) {
                return position;
            }
        }
    }
    return Vec2i();
}
