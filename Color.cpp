#include "Color.h"


Color::Color()
    : r(0.0f)
    , g(0.0f)
    , b(0.0f)
{
}

Color::Color(float r, float g, float b)
    : r(r)
    , g(g)
    , b(b)
{
}

Color& Color::operator+(const Color& c)
{
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

Color Color::operator+(const Color& c) const
{
    return Color(r + c.r, g + c.g, b + c.b);
}

Color& Color::operator+=(const Color& c)
{
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

Color& Color::operator-=(const Color& c)
{
    r -= c.r;
    g -= c.g;
    b -= c.b;
    return *this;
}

Color& Color::operator*(const Color& c)
{
    r *= c.r;
    g *= c.g;
    b *= c.b;
    return *this;
}

Color Color::operator*(const Color& c) const
{
    return Color(r * c.r, g * c.g, b * c.b);
}

Color& Color::operator-(const Color& c)
{
    r -= c.r;
    g -= c.g;
    b -= c.b;
    return *this;
}

Color Color::operator-(const Color& c) const
{
    return Color(r - c.r, g - c.g, b - c.b);
}

Color& Color::operator+(float f)
{
    r += f;
    g += f;
    b += f;
    return *this;
}

Color Color::operator+(float f) const
{
    return Color(r + f, g + f, b + f);
}

Color& Color::operator-(float f)
{
    r -= f;
    g -= f;
    b -= f;
    return *this;
}

Color Color::operator-(float f) const
{
    return Color(r - f, g - f, b - f);
}

Color& Color::operator*(float f)
{
    r *= f;
    g *= f;
    b *= f;
    return *this;
}

Color Color::operator*(float f) const
{
    return Color(r * f, g * f, b * f);
}
