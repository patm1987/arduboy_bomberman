#include "stdafx.h"

#include "Bomb.h"
#include "Constants.h"
#include "ExplosionManager.h"
#include "Map.h"
#include "MapAssets.h"
#include "Player.h"
#include "SpriteAssets.h"
#include "UnorderedFixedSizeList.h"

Arduboy arduboy;

Map::MapConfig mapConfig = {
    aMapData,
    aFloorTile,
    aWallTile,
    aSpawnTile};

Map defaultMap(mapConfig);

Player player(aPlayer, &defaultMap);

// TODO: these should be circular lists
UnorderedFixedSizeList<Bomb, BombCount> bombs;

ExplosionManager explosionManager(defaultMap);

bool bWasPressed = false;

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

    if (arduboy.pressed(B_BUTTON) && !bWasPressed)
    {
        bWasPressed = true;
        bombs.add(Bomb(BombTime, player.getPosition()));
    }
    else if (!arduboy.pressed(B_BUTTON) && bWasPressed)
    {
        bWasPressed = false;
    }

    for (auto &bomb : bombs)
    {
        bomb.update();
    }
    for (int i = 0; i < bombs.length();)
    {
        if (bombs[i].getFramesRemaining() <= 0)
        {
            explosionManager.addExplosion(bombs[i].getPosition());
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

    explosionManager.update();
    explosionManager.draw(arduboy);

    player.draw(arduboy);
    arduboy.display();
}
