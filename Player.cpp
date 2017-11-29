#include "stdafx.h"

#include "Player.h"

void Player::draw(const Arduboy& arduboy) const {
    arduboy.drawRect(X, Y, PlayerWidth, PlayerHeight, BLACK);
    arduboy.drawBitmap(X, Y, _pPlayerImage, PlayerWidth, PlayerHeight, WHITE);
}