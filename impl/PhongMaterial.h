#ifndef PHONGMATERIAL_H
#define PHONGMATERIAL_H

#include "Color.h"
#include "Material.h"


/*
 * \brief Phong material.
 *
 * Ambient, diffuse and specular reflection.
 */
class PhongMaterial : public Material
{
public:
    PhongMaterial(const Color& ambient, const Color& diffuse, const Color& specular,
                  double shininess);

    virtual Color shade(const Intersection& intersection, const Scene& scene) const override;
private:
    const Color c_ambient;    // Ambient color coefficient
    const Color c_diffuse;    // Diffuse color coefficient
    const Color c_specular;   // Specular color coefficient
    const double s;           // Shininess exponent
};

#endif //ifndef PHONGMATERIAL_H

