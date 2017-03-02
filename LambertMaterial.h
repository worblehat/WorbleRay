
#ifndef LAMBERTMATERIAL_H
#define LAMBERTMATERIAL_H

#include "Color.h"
#include "Intersection.h"
#include "Material.h"
#include "Scene.h"

/*
 * \brief Lambertian material.
 *
 * Only diffuse reflection which is independent of view point and calculated from the angle between
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

