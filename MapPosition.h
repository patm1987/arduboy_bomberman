#ifndef _MAP_POSITION_H
#define _MAP_POSITION_H

#include "stdafx.h"

#include "Vec2i.h"

class Map;

/*!
 * Represents the position of an object on the map and facilitates moving it
 */
class MapPosition
{
  public:
    MapPosition(int16_t framesPerTile = 0);
    MapPosition(const Vec2i &tilePosition, int16_t framesPerTile = 0);
    MapPosition(const MapPosition &other);

    void update();
    Vec2i getPixelPosition() const;
    const Vec2i &getPosition() const;

    int16_t getFramesUntilArrival() const;

    void moveTo(const Vec2i &nextTile);
    void setPosition(const Vec2i &position);

  private:
    const int16_t _framesPerTile;
    int16_t _framesUntilArrival;
    Vec2i _currentTile;
    Vec2i _nextTile;
};

inline MapPosition::MapPosition(int16_t framesPerTile)
    : _framesPerTile(framesPerTile),
      _framesUntilArrival(0),
      _currentTile(Vec2i()),
      _nextTile(Vec2i()) {}
inline MapPosition::MapPosition(const Vec2i &tilePosition, int16_t framesPerTile)
    : _framesPerTile(framesPerTile),
      _framesUntilArrival(0),
      _currentTile(tilePosition),
      _nextTile(tilePosition) {}
inline MapPosition::MapPosition(const MapPosition &other)
    : _framesPerTile(other._framesPerTile),
      _framesUntilArrival(other._framesUntilArrival),
      _currentTile(other._currentTile),
      _nextTile(other._nextTile) {}

inline const Vec2i &MapPosition::getPosition() const
{
    return _currentTile;
}

inline int16_t MapPosition::getFramesUntilArrival() const
{
    return _framesUntilArrival;
}

inline void MapPosition::moveTo(const Vec2i &nextTile)
{
    if (nextTile == _currentTile)
    {
        return;
    }
    _currentTile = _nextTile;
    _nextTile = nextTile;
    _framesUntilArrival = _framesPerTile;
}

inline void MapPosition::setPosition(const Vec2i &position)
{
    _currentTile = position;
    _nextTile = position;
    _framesUntilArrival = 0;
}

#endif //_MAP_POSITION_H