#include "Intersection.h"
#include "log.h"
#include "PointLight.h"
#include "Ray.h"
#include "Scene.h"
#include "VectorD.h"

PointLight::PointLight(const PointD3& position, const Color& color, float radiance)
    : Light(color, radiance)
    , position(position)
{
}

VectorD PointLight::direction_at(const PointD3& point) const
{
    VectorD direction = point - position;
    direction.normalize();
    return direction;
}

Color PointLight::intensity(const PointD3& point, const Scene& scene) const
{
    if(scene.options().shadows)
    {
        // Cast a ray from light to the point
        VectorD shadow_vec = position - point;
        Ray shadow_ray(point, shadow_vec);
        Intersection intersection = scene.trace(shadow_ray);

        // Is there any object between light and point?
        double light_dist = shadow_vec.length();
        if(intersection.exists && intersection.t < light_dist)
        {
            return Color();
        }
    }

    return color * radiance;
}

