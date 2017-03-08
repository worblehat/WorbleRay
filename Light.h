
#ifndef LIGHT_H
#define LIGHT_H

#include "Color.h"
#include "VectorD.h"

class Intersection;

/**
 * \brief Abstract base class for lights.
 */
class Light
{
    public:
        Light();
        Light(const Color& color, float radiance = 1.0);
        virtual ~Light(){};
        /**
         * \brief Get the normalized incomming direction of the light at an intersection point.
         * Used as "light vector" in shading calculations."
         */
        virtual VectorD get_direction(const Intersection& intersection) const = 0;
        virtual Color get_intensity() const = 0;
        virtual void set_radiance(float r);
        virtual void set_color(const Color& c);
    protected:
        float radiance;
        Color color;
};

inline Light::Light()
 : color(Color(1.0, 1.0, 1.0))
, radiance(1.0)
{
}

inline Light::Light(const Color& color, float radiance)
 : color(color)
 , radiance(radiance)
{
}

inline void Light::set_radiance(float r)
{
    radiance = r;
}

inline void Light::set_color(const Color& c)
{
    color = c;
}

#endif //ifndef LIGHT_H
