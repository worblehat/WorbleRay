
#include "PointLight.h"


Vector4d PointLight::get_direction(const Intersection& intersection) const
{
    return glm::normalize(Vector4d(intersection.get_hit_point() - position));
}

Color PointLight::get_intensity() const
{
    return color * radiance;
}

