#include "stdafx.h"

#include "Map.h"
#include "MapAssets.h"

Arduboy arduboy;

const uint8_t aMapData[] PROGMEM = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1,
    1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

Map::MapConfig mapConfig = {
    aMapData,
    aFloorTile,
    aWallTile,
    aSpawnTile
};

Map defaultMap(mapConfig);

void setup() {
    arduboy.begin();
}

void loop() {
    arduboy.clear();
    arduboy.setCursor(0, 0);
    defaultMap.draw(arduboy);
    arduboy.display();
}

