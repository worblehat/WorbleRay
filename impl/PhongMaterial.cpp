#include "AmbientLight.h"
#include "Intersection.h"
#include "log.h"
#include "Light.h"
#include "PhongMaterial.h"
#include "Scene.h"
#include "VectorD.h"

#include <cmath>
#include <vector>


PhongMaterial::PhongMaterial(const Color& ambient, const Color& diffuse, const Color& specular,
                             double shininess)
    : Material()
    , c_ambient(ambient)
    , c_diffuse(diffuse)
    , c_specular(specular)
    , s(shininess)
{
}

Color PhongMaterial::shade(const Intersection& intersection, const Scene& scene) const
{
    Color intensity;
    PointD point = intersection.hit_point;
    Options options = scene.options();

    if(options.diffuse_illumination || options.specular_illumination)
    {
        Color i_diffuse;
        Color i_specular;
        VectorD n = intersection.normal;
        for(auto &light : scene.lights())
        {
            VectorD l = -1 * light->direction_at(point);
            float n_dot_l = n.dot(l);
            Color i_light = light->intensity(point, scene);

            // === Diffuse reflection ===
            if(options.diffuse_illumination)
            {
                if(n_dot_l > 0.0f)
                {
                    i_diffuse = i_light * c_diffuse * n_dot_l;
                }
            }

            // === Specular reflection ===
            if(options.specular_illumination)
            {
                VectorD v = -1 * intersection.incident_ray.direction;
                VectorD r = 2 * n_dot_l * n - l;
                r.normalize();
                float v_dot_r = v.dot(r);
                if(v_dot_r > 0.0f)
                {
                   i_specular = i_light * c_specular * std::pow(v_dot_r, s);
                }
            }
        }
        intensity += i_diffuse;
        intensity += i_specular;
    }

    // === Ambient reflection ===
    if(options.ambient_illumination)
    {
        auto ambient_light = scene.ambient_light();
        if(ambient_light)
        {
          Color i_light = scene.ambient_light()->intensity(point, scene);
          Color i_ambient = i_light * c_ambient;
          intensity += i_ambient;
        }
    }


    return intensity;
}

