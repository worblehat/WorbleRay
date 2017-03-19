#include "Intersection.h"
#include "log.h"
#include "PointLight.h"
#include "Ray.h"
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
    if(scene.options().shadows)
    {
        // Cast a ray from light to the point
        VectorD shadow_vec = point - position;
        Ray shadow_ray(position, shadow_vec);
        Intersection intersection = scene.trace(shadow_ray);

        // Is there any object between light and point?
        double point_dist = shadow_vec.length();
        if(intersection.exists && intersection.t < point_dist) //TODO do we need an epsilon here?
        {
            return Color();
        }
    }

    return color * radiance;
}

