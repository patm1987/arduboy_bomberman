#include "stdafx.h"

#include "Player.h"

#include "Vec2i.h"

void Player::processInput(Arduboy &arduboy)
{
    Vec2i nextPosition = _position.getPosition();
    if (arduboy.pressed(UP_BUTTON))
    {
        nextPosition.Y -= 1;
    }
    if (arduboy.pressed(DOWN_BUTTON))
    {
        nextPosition.Y += 1;
    }
    if (arduboy.pressed(LEFT_BUTTON))
    {
        nextPosition.X -= 1;
    }
    if (arduboy.pressed(RIGHT_BUTTON))
    {
        nextPosition.X += 1;
    }
    _position.moveTo(nextPosition);
}

void Player::update(Arduboy &arduboy)
{
    _position.update();
    if (_position.getFramesUntilArrival() == 0)
    {
        processInput(arduboy);
    }
}

void Player::draw(Arduboy &arduboy) const
{
    Vec2i pixelPosition = _position.getPixelPosition();
    arduboy.drawRect(pixelPosition.X, pixelPosition.Y, PlayerWidth, PlayerHeight, BLACK);
    arduboy.drawBitmap(pixelPosition.X, pixelPosition.Y, _pPlayerImage, PlayerWidth, PlayerHeight, WHITE);
}