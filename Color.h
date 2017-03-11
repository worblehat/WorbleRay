#ifndef COLOR_H
#define COLOR_H

#include <string>


/**
 * \brief RGB-color.
 *
 * The color componentes are represented by floating point numbers in the interval [0,1].
 * Basic arithmetic operations on the color are provided.
 *
 * \note There is no validation of component values implemented. The user has to take care that the
 * color values represent a valid color by himself.
 */
class Color
{
public:
    Color();
    Color(float r, float g, float b);

    std::string str() const;

    Color& operator+(const Color& c);
    Color operator+(const Color& c) const;
    Color& operator-(const Color& c);
    Color operator-(const Color& c) const;
    Color& operator+=(const Color& c);
    Color& operator-=(const Color& c);
    Color& operator*(const Color& c);
    Color operator*(const Color& c) const;
    Color& operator+(float f);
    Color operator+(float f) const;
    Color& operator-(float f);
    Color operator-(float f) const;
    Color& operator*(float f);
    Color operator*(float f) const;

public:
    float r;
    float g;
    float b;
};


#endif //ifndef COLOR_H
