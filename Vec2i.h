#ifndef _VEC2I_H
#define _VEC2I_H

#include "stdafx.h"

class Vec2i
{
  public:
    explicit constexpr Vec2i(int16_t x = 0, int16_t y = 0) : X(x), Y(y) {}
    constexpr Vec2i(const Vec2i &org) : X(org.X), Y(org.Y) {}

    Vec2i &operator=(const Vec2i &other);
    constexpr bool operator==(const Vec2i &other) const;
    constexpr Vec2i operator*(int16_t scale) const;
    constexpr Vec2i operator/(int16_t invScale) const;
    constexpr Vec2i operator+(const Vec2i &other) const;
    constexpr Vec2i operator-(const Vec2i &other) const;

    union {
        struct
        {
            int16_t X;
            int16_t Y;
        };
        int16_t Elems[2];
    };

  private:
};

constexpr Vec2i operator*(int16_t scale, const Vec2i &vec);

inline Vec2i &Vec2i::operator=(const Vec2i &other)
{
    X = other.X;
    Y = other.Y;
}

inline constexpr bool Vec2i::operator==(const Vec2i &other) const
{
    return other.X == X && other.Y == Y;
}

inline constexpr Vec2i Vec2i::operator*(int16_t scale) const
{
    return Vec2i(X * scale, Y * scale);
}

inline constexpr Vec2i Vec2i::operator/(int16_t invScale) const
{
    return Vec2i(X / invScale, Y / invScale);
}

inline constexpr Vec2i Vec2i::operator+(const Vec2i &other) const
{
    return Vec2i(X + other.X, Y + other.Y);
}

inline constexpr Vec2i Vec2i::operator-(const Vec2i &other) const
{
    return Vec2i(X - other.X, Y - other.Y);
}

inline constexpr Vec2i operator*(int16_t scale, const Vec2i &vec)
{
    return Vec2i(scale * vec.X, scale * vec.Y);
}

#endif //_VEC2I_H