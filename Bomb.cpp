#include "stdafx.h"

#include "Bomb.h"

#include "SpriteAssets.h"
#include "Map.h"

void Bomb::update()
{
    _framesRemaining--;
}

void Bomb::draw(Arduboy &arduboy)
{
    Vec2i pixelPosition = Map::mapPositionToPixelPosition(_position);
    arduboy.drawBitmap(pixelPosition.X, pixelPosition.Y, aBomb, SpriteWidth, SpriteHeight, WHITE);
}
