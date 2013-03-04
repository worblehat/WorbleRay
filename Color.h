#ifndef COLOR_H
#define COLOR_H

class Color
{
    public:
        Color(float r, float g, float b);

        float get_r() const;
        float get_g() const;
        float get_b() const;

    private:
        float r;
        float g;
        float b;
};

inline Color::Color(float r, float g, float b)
 : r(r)
 , g(g)
 , b(b)
{
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

#endif //ifndef COLOR_H
