#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>

#include "MapPosition.h"

class Arduboy;

class Player
{
  public:
    static const uint8_t PlayerWidth = 8;
    static const uint8_t PlayerHeight = 8;

    explicit Player(const uint8_t *pPlayerImage);

    void update(Arduboy &arduboy);
    void draw(Arduboy &arduboy) const;

    void setPosition(const Vec2i &position);

  private:
    void processInput(Arduboy &arduboy);

    const uint8_t *_pPlayerImage;
    MapPosition _position;
};

inline Player::Player(const uint8_t *pPlayerImage) : _position(20), _pPlayerImage(pPlayerImage)
{
}

inline void Player::setPosition(const Vec2i& position)
{
    _position.setPosition(position);
}

#endif //_PLAYER_H