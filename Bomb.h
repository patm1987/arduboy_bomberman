#ifndef _BOMB_H
#define _BOMB_H

#include "MapPosition.h"

class Bomb
{
  public:
    explicit Bomb(int framesToLive = 0);
    Bomb(int framesToLive, const MapPosition &position);
    Bomb(const Bomb &bomb);

    Bomb &operator=(const Bomb &other);

    void update();
    void draw(Arduboy &arduboy);

    int getFramesRemaining() const;

  private:
    MapPosition _position;
    int _framesRemaining;
};

inline Bomb::Bomb(int framesToLive)
    : _position(),
      _framesRemaining(framesToLive) {}
inline Bomb::Bomb(int framesToLive, const MapPosition &position)
    : _position(position),
      _framesRemaining(framesToLive) {}
inline Bomb::Bomb(const Bomb &bomb)
    : _position(bomb._position),
      _framesRemaining(bomb._framesRemaining) {}

inline Bomb &Bomb::operator=(const Bomb &other)
{
    _position = other._position;
    _framesRemaining = other._framesRemaining;
    return *this;
}

inline int Bomb::getFramesRemaining() const
{
    return _framesRemaining;
}

#endif //_BOMB_H