#include "stdafx.h"

#include "ExplosionManager.h"

#include "SpriteAssets.h"
#include "Map.h"

void ExplosionManager::addExplosion(const Vec2i &position)
{
    _explosionList.add((Explosion){position, ExplosionTime});
}

void ExplosionManager::update()
{
    int i = 0;
    while (i < _explosionList.length())
    {
        auto &explosion = _explosionList[i];
        explosion.ticksRemaining--;
        if (explosion.ticksRemaining <= 0)
        {
            _explosionList.remove(i);
        }
        else
        {
            i++;
        }
    }
}

void ExplosionManager::draw(Arduboy &arduboy) const
{
    for (const auto &explosion : _explosionList)
    {
        Vec2i pixelPosition = Map::mapPositionToPixelPosition(explosion.location);
        arduboy.drawBitmap(pixelPosition.X, pixelPosition.Y, aExplosion, SpriteWidth, SpriteHeight, WHITE);
    }
}