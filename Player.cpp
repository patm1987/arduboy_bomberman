#include "stdafx.h"

#include "Player.h"

#include "Map.h"
#include "SpriteAssets.h"
#include "Vec2i.h"
#include <assert.h>

void Player::processInput(Arduboy &arduboy)
{
    assert(_pMap);

    Vec2i nextPosition = _position.getPosition();
    if (_pMap->isSpaceEmpty(Vec2i(nextPosition.X, nextPosition.Y - 1)) && arduboy.pressed(UP_BUTTON))
    {
        nextPosition.Y -= 1;
    }
    else if (_pMap->isSpaceEmpty(Vec2i(nextPosition.X, nextPosition.Y + 1)) && arduboy.pressed(DOWN_BUTTON))
    {
        nextPosition.Y += 1;
    }
    else if (_pMap->isSpaceEmpty(Vec2i(nextPosition.X - 1, nextPosition.Y)) && arduboy.pressed(LEFT_BUTTON))
    {
        nextPosition.X -= 1;
    }
    else if (_pMap->isSpaceEmpty(Vec2i(nextPosition.X + 1, nextPosition.Y)) && arduboy.pressed(RIGHT_BUTTON))
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
    arduboy.fillRect(pixelPosition.X, pixelPosition.Y, SpriteWidth, SpriteHeight, BLACK);
    arduboy.drawBitmap(pixelPosition.X, pixelPosition.Y, aPlayer, SpriteWidth, SpriteHeight, WHITE);
}