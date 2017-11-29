#include "stdafx.h"

#include "Player.h"

void Player::processInput(const Arduboy& arduboy) {
    if (arduboy.pressed(UP_BUTTON)) {
        Y -= 1;
    }
    if (arduboy.pressed(DOWN_BUTTON)) {
        Y += 1;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
        X -= 1;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
        X += 1;
    }
}

void Player::draw(const Arduboy& arduboy) const {
    arduboy.drawRect(X, Y, PlayerWidth, PlayerHeight, BLACK);
    arduboy.drawBitmap(X, Y, _pPlayerImage, PlayerWidth, PlayerHeight, WHITE);
}