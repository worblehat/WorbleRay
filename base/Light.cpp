#include "Light.h"


Light::Light()
    : color(Color(1.0, 1.0, 1.0))
    , radiance(1.0)
{
}

Light::Light(const Color& color, float radiance)
    : color(color)
    , radiance(radiance)
{
}

void Light::set_radiance(float r)
{
    radiance = r;
}

void Light::set_color(const Color& c)
{
    color = c;
}

