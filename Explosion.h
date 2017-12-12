#ifndef _EXPLOSION_H
#define _EXPLOSION_H

#include "Vec2i.h"

struct Explosion
{
    Vec2i location;
    int ticksRemaining;
};

#endif //_EXPLOSION_H