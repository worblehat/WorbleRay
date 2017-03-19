#include "PointLight.h"
#include "Scene.h"
#include "VectorD.h"


PointLight::PointLight(const PointD& position, const Color& color, float radiance)
    : Light(color, radiance)
    , position(position)
{
}

VectorD PointLight::direction_at(const PointD& point) const
{
    VectorD direction = point - position;
    direction.normalize();
    return direction;
}

Color PointLight::intensity(const PointD& point, const Scene& scene) const
{
    return color * radiance;
}

