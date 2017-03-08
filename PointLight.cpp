
#include "PointLight.h"


VectorD PointLight::get_direction(const Intersection& intersection) const
{
    VectorD direction = intersection.get_hit_point() - position;
    direction.normalize();
    return direction;
}

Color PointLight::get_intensity() const
{
    return color * radiance;
}

