#ifndef _EXPLOSION_MANAGER_H
#define _EXPLOSION_MANAGER_H

class Vec2i;
class Map;

#include "Constants.h"
#include "Explosion.h"
#include "UnorderedFixedSizeList.h"

class ExplosionManager
{
  public:
    explicit ExplosionManager(const Map &map);

    void addExplosion(const Vec2i &position);
    void update();
    void draw(Arduboy &arduboy) const;

  private:
    // 1 bomb at each bomb location plus distance number of explosions per cardinal direction
    UnorderedFixedSizeList<Explosion, ExplosionDistancePerBomb * BombCount * 4 + BombCount> _explosionList;

    const Map &_map;
};

inline ExplosionManager::ExplosionManager(const Map &map) : _map(map) {}

#endif //_EXPLOSION_MANAGER_H