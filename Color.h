/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef COLOR_H
#define COLOR_H

/**
 * \brief This class represents a RGB color.
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

        float get_r() const;
        float get_g() const;
        float get_b() const;
        void set_r(float r);
        void set_g(float g);
        void set_b(float b);

    private:
        float r;
        float g;
        float b;
};

inline Color::Color()
 : r(0.0f)
 , g(0.0f)
 , b(0.0f)
{
}

inline Color::Color(float r, float g, float b)
 : r(r)
 , g(g)
 , b(b)
{
}

inline Color& Color::operator+(const Color& c)
{
    r += c.get_r();
    g += c.get_g();
    b += c.get_b();
    return *this;
}

inline Color Color::operator+(const Color& c) const
{
    return Color(r + c.get_r(), g + c.get_g(), b + c.get_b());
}

inline Color& Color::operator+=(const Color& c)
{
    r += c.get_r();
    g += c.get_g();
    b += c.get_b();
    return *this;
}

inline Color& Color::operator-=(const Color& c)
{
    r -= c.get_r();
    g -= c.get_g();
    b -= c.get_b();
    return *this;
}

inline Color& Color::operator*(const Color& c)
{
    r *= c.get_r();
    g *= c.get_g();
    b *= c.get_b();
    return *this;
}
    
inline Color Color::operator*(const Color& c) const
{
    return Color(r * c.get_r(), g * c.get_g(), b * c.get_b());
}

inline Color& Color::operator-(const Color& c)
{
    r -= c.get_r();
    g -= c.get_g();
    b -= c.get_b();
    return *this;
}

inline Color Color::operator-(const Color& c) const
{
    return Color(r - c.get_r(), g - c.get_g(), b - c.get_b());
}

inline Color& Color::operator+(float f)
{
    r += f;
    g += f; 
    b += f;
    return *this;
}

inline Color Color::operator+(float f) const 
{
    return Color(r + f, g + f, b + f);
}

inline Color& Color::operator-(float f)
{
    r -= f;
    g -= f; 
    b -= f;
    return *this;
}

inline Color Color::operator-(float f) const 
{
    return Color(r - f, g - f, b - f);
}

inline Color& Color::operator*(float f)
{
    r *= f;
    g *= f; 
    b *= f;
    return *this;
}

inline Color Color::operator*(float f) const 
{
    return Color(r * f, g * f, b * f);
}
        
inline float Color::get_r() const
{
    return r;
}

inline float Color::get_g() const
{
    return g;
}

inline float Color::get_b() const
{
    return b;
}
    
inline void Color::set_r(float r) 
{
    this->r = r;
}

inline void Color::set_g(float g)
{
    this->g = g;
}

inline void Color::set_b(float b)
{
    this->b = b;
}

#endif //ifndef COLOR_H
