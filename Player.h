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

    void update(const Arduboy &arduboy);
    void draw(const Arduboy &arduboy) const;

  private:
    void processInput(const Arduboy &arduboy);

    const uint8_t *_pPlayerImage;
    MapPosition _position;
};

inline Player::Player(const uint8_t *pPlayerImage) : _position(20), _pPlayerImage(pPlayerImage)
{
}

#endif //_PLAYER_H