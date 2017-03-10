#ifndef LAMBERTMATERIAL_H
#define LAMBERTMATERIAL_H

#include "Color.h"
#include "Material.h"


/*
 * \brief Lambertian material.
 *
 * Diffuse-only reflection which is independent of view point and calculated from the angle between
 * surface normal and light vector.
 */
class LambertMaterial : public Material
{
public:
    LambertMaterial(const Color& ambient,const Color& diffuse);

    virtual Color shade(const Intersection& intersection, const Scene& scene) const override;
private:
    const Color c_ambient;    // Ambient color coefficient
    const Color c_diffuse;    // Diffuse color coefficient
};

#endif //ifndef LAMBERTMATERIAL_H

