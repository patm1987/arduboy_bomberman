#ifndef _MAP_ASSETS_H
#define _MAP_ASSETS_H

#include "stdafx.h"

const uint8_t aFloorTile[] PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t aWallTile[] PROGMEM = {0x7E, 0xC3, 0xA5, 0x99, 0x99, 0xA5, 0xC3, 0x7E};
const uint8_t aSpawnTile[] PROGMEM = { 0x30, 0x70, 0x63, 0xff, 0xff, 0x63, 0x70, 0x30 };

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

#endif//_MAP_ASSETS_H