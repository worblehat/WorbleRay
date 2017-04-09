#include "AmbientLight.h"
#include "Color.h"
#include "Intersection.h"
#include "PointD3.h"
#include "VectorD.h"


AmbientLight::AmbientLight()
    : Light(Color(1.0, 1.0, 1.0), 1.0f)
{
}

AmbientLight::AmbientLight(const Color& color, float radiance)
    : Light(color, radiance)
{
}

VectorD AmbientLight::direction_at(const PointD3& point) const
{
    return VectorD(0.0, 0.0, 0.0);
}

Color AmbientLight::intensity(const PointD3& point, const Scene& scene) const
{
    return color * radiance;
}

