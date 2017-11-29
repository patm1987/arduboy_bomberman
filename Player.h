#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>

class Arduboy;

class Player {
public:
    static const uint8_t PlayerWidth = 8;
    static const uint8_t PlayerHeight = 8;

    explicit Player(const uint8_t* pPlayerImage);

    void processInput(const Arduboy& arduboy);
    void draw(const Arduboy& arduboy) const;

    int16_t X;
    int16_t Y;

private:
    const uint8_t* _pPlayerImage;
};

inline Player::Player(const uint8_t* pPlayerImage): X(0), Y(0), _pPlayerImage(pPlayerImage) {
}

#endif//_PLAYER_H