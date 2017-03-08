
#include "AmbientLight.h"


AmbientLight::AmbientLight()
: Light(Color(1.0, 1.0, 1.0), 1.0f)
{
}

AmbientLight::AmbientLight(const Color& color, float radiance)
 : Light(color, radiance)
{
}

VectorD AmbientLight::get_direction(const Intersection& intersection) const
{
    return VectorD(0.0, 0.0, 0.0);
}

Color AmbientLight::get_intensity() const
{
    return color * radiance;
}

