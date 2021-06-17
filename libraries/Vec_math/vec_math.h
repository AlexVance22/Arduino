#ifndef VEC_MATH_H
#define VEC_MATH_H


template<typename Ty>
class Vector2
{
    Ty x, y;

    Vector2(Ty _x, Ty _y) : x(_x), y(_y) {}

    Vector2 operator+(Vector2 other)
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(Vector2 other)
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(Ty other)
    {
        return Vector2(x * other, y * other);
    }

    Ty operator*(Vector2 other)
    {
        return x * other.x + y * other.y;
    }

    void operator+=(Vector2 other)
    {
        x += other.x;
        y += other.y;
    }

    void operator-=(Vector2 other)
    {
        x -= other.x;
        y -= other.y;
    }

    void operator*=(Ty other)
    {
        x *= other;
        y *= other;
    }
};

#endif