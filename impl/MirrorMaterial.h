#ifndef MIRRORMATERIAL_H
#define MIRRORMATERIAL_H

#include "Material.h"

/*! \brief A perfect mirror that reflects incoming light unmodified.
 *
 *  Does not contribute any color by itself to the reflection but returns
 *  black if the incoming ray has reached maximum recursion depth.
 */
class MirrorMaterial : public Material
{
public:
    MirrorMaterial();
    virtual Color shade(const Intersection& intersection, const Scene& scene) const override;
};

#endif // MIRRORMATERIAL_H
