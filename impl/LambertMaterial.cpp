#include "AmbientLight.h"
#include "Intersection.h"
#include "LambertMaterial.h"
#include "Light.h"
#include "Scene.h"
#include "VectorD.h"

#include <vector>


LambertMaterial::LambertMaterial(const Color& ambient, const Color& diffuse)
    : Material()
    , c_ambient(ambient)
    , c_diffuse(diffuse)
{
}

Color LambertMaterial::shade(const Intersection& intersection, const Scene& scene) const
{
    Color intensity;

    // === Diffuse reflection ===
    Color intensity_diffuse;
    for(auto &light : scene.lights())
    {
        VectorD n = intersection.normal;
        VectorD l = -1.0 * light->direction_at(intersection.hit_point);
        float dot = n.dot(l);
        if(dot > 0.0f)
        {
            intensity_diffuse += light->intensity() * c_diffuse * dot;
        }
    }
    intensity += intensity_diffuse;

    // === Ambient reflection ===
    auto ambient_light = scene.ambient_light();
    if(ambient_light)
    {
      Color ambient_intensity = scene.ambient_light()->intensity();
      Color intensity_ambient = ambient_intensity * c_ambient;
      intensity += intensity_ambient;
    }

    return intensity;
}

