#include "stdafx.h"

#include "MapPosition.h"

#include "Map.h"

void MapPosition::update()
{
    if (_framesUntilArrival > 0) 
    {
        _framesUntilArrival--;
        if (_framesUntilArrival == 0)
        {
            _currentTile = _nextTile;
        }
    }
}

Vec2i MapPosition::getPixelPosition() const
{
    if (_framesUntilArrival == 0)
    {
        return Map::mapPositionToPixelPosition(_currentTile);
    }

    Vec2i currentPosition = Map::mapPositionToPixelPosition(_currentTile);
    Vec2i nextPosition = Map::mapPositionToPixelPosition(_nextTile);
    Vec2i invDeltaPosition = currentPosition - nextPosition;
    return ((_framesUntilArrival * currentPosition - _framesUntilArrival * nextPosition) / _framesPerTile) + nextPosition;
}
