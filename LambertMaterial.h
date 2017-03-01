
#ifndef LAMBERTMATERIAL_H
#define LAMBERTMATERIAL_H

#include "Color.h"
#include "Intersection.h"
#include "Material.h"
#include "Scene.h"

/*
 * \brief Simple Material that provides a flat shading with lambertian illumination. 
 *
 * Uses the surface normal and light vectors to calculate a color value.
 */ 
class LambertMaterial : public Material
{
    public:
        LambertMaterial();
        LambertMaterial(const Color& ambient,const Color& diffuse);

        virtual Color shade(const Intersection& intersection, const Scene& scene) const;
    private:
        Color c_ambient;    // Ambient color coefficient
        Color c_diffuse;    // Diffuse color coefficient
};

inline LambertMaterial::LambertMaterial()
 : Material()
 , c_ambient(Color(0.5f, 0.5f, 0.5f))
 , c_diffuse(Color(0.5f, 0.5f, 0.5f))
{
}
        
inline LambertMaterial::LambertMaterial(const Color& ambient, const Color& diffuse)
{
    c_ambient = ambient;
    c_diffuse = diffuse; 
}

#endif //ifndef LAMBERTMATERIAL_H

