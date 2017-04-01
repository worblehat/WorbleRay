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

    //! color = color + color
    Color operator+(const Color& c) const;
    //! color += color
    Color& operator+=(const Color& c);
    //! color = color - color
    Color operator-(const Color& c) const;
    //! color -= color
    Color& operator-=(const Color& c);
    //! color = color * color
    Color operator*(const Color& c) const;
    //! color*-= color
    Color& operator*=(const Color& c);
    //! color = color + float
    Color operator+(float f) const;
    //! color += float
    Color& operator+=(float f);
    //! color = color - float
    Color operator-(float f) const;
    //! color -= float
    Color& operator-=(float f);
    //! color = color * float
    Color operator*(float f) const;
    //! color *= float
    Color& operator*=(float f);
    //! color = color / float
    Color operator/(float f) const;
    //! color /= float
    Color& operator/=(float f);

public:
    float r;
    float g;
    float b;
};


#endif //ifndef COLOR_H
