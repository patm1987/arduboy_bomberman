#include "stdafx.h"

#include "Bomb.h"
#include "Map.h"
#include "MapAssets.h"
#include "Player.h"
#include "PlayerAssets.h"
#include "UnorderedFixedSizeList.h"

Arduboy arduboy;

const int BombTime = 120;

Map::MapConfig mapConfig = {
    aMapData,
    aFloorTile,
    aWallTile,
    aSpawnTile};

Map defaultMap(mapConfig);

Player player(aPlayer, &defaultMap);

UnorderedFixedSizeList<Bomb> bombs;

bool aWasPressed = false;

void setup()
{
    arduboy.begin();
    player.setPosition(defaultMap.getPlayerSpawnPosition());
}

void loop()
{
    arduboy.clear();
    arduboy.setCursor(0, 0);
    defaultMap.draw(arduboy);
    player.update(arduboy);

    if (arduboy.pressed(A_BUTTON) && !aWasPressed)
    {
        aWasPressed = true;
        bombs.add(Bomb(BombTime, player.getPosition()));
    }
    else if (!arduboy.pressed(A_BUTTON) && aWasPressed)
    {
        aWasPressed = false;
    }

    for (auto &bomb : bombs)
    {
        bomb.update();
    }
    for (int i = 0; i < bombs.length();)
    {
        if (bombs[i].getFramesRemaining() <= 0)
        {
            bombs.remove(i);
        }
        else
        {
            i++;
        }
    }
    for (auto &bomb : bombs)
    {
        bomb.draw(arduboy);
    }

    player.draw(arduboy);
    arduboy.display();
}
