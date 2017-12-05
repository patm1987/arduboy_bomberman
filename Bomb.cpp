#include "stdafx.h"

#include "Bomb.h"

#include "PlayerAssets.h"

void Bomb::update()
{
    _framesRemaining--;
}

void Bomb::draw(Arduboy &arduboy)
{
    Vec2i position = _position.getPixelPosition();
    arduboy.drawBitmap(position.X, position.Y, aBomb, SpriteWidth, SpriteHeight, WHITE);
}
