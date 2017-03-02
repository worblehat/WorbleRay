
#include "LambertMaterial.h"

#include "AmbientLight.h"
#include "Light.h"

#include <iostream>
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
    for(Light* light : scene.get_lights())
    {
        Vector4d n = intersection.get_normal();
        Vector4d l = -1.0 * light->get_direction(intersection);
        float dot = glm::dot(n, l);
        if(dot > 0.0f)
        {
            intensity_diffuse += light->get_intensity() * c_diffuse * dot;
        }
    }
    intensity += intensity_diffuse;

    // === Ambient reflection ===
    Color ambient_light = scene.get_ambient_light()->get_intensity();
    Color intensity_ambient = ambient_light * c_ambient;
    intensity += intensity_ambient;

    return intensity;
}

