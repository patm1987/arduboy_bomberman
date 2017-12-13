#include "stdafx.h"

#include "ExplosionManager.h"

#include "SpriteAssets.h"
#include "Map.h"

void ExplosionManager::addExplosion(const Vec2i &position)
{
    _explosionList.add((Explosion){position, ExplosionTime});
    // explode up
    for (int i = 0; i < ExplosionDistancePerBomb; i++)
    {
        Vec2i testSpace = position - Vec2i(0, i + 1);
        if (_map.isSpaceEmpty(testSpace))
        {
            _explosionList.add((Explosion){testSpace, ExplosionTime});
        }
        else
        {
            break;
        }
    }
    // explode down
    for (int i = 0; i < ExplosionDistancePerBomb; i++)
    {
        Vec2i testSpace = position + Vec2i(0, i + 1);
        if (_map.isSpaceEmpty(testSpace))
        {
            _explosionList.add((Explosion){testSpace, ExplosionTime});
        }
        else
        {
            break;
        }
    }
    // explode left
    for (int i = 0; i < ExplosionDistancePerBomb; i++)
    {
        Vec2i testSpace = position - Vec2i(i + 1, 0);
        if (_map.isSpaceEmpty(testSpace))
        {
            _explosionList.add((Explosion){testSpace, ExplosionTime});
        }
        else
        {
            break;
        }
    }
    // explode right
    for (int i = 0; i < ExplosionDistancePerBomb; i++)
    {
        Vec2i testSpace = position + Vec2i(i + 1, 0);
        if (_map.isSpaceEmpty(testSpace))
        {
            _explosionList.add((Explosion){testSpace, ExplosionTime});
        }
        else
        {
            break;
        }
    }
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