#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "Light.h"


/**
 * \brief Ambient light source without position and direction.
 */
class AmbientLight : public Light
{
public:
    AmbientLight();
    explicit AmbientLight(const Color& color, float radiance = 1.0);
    virtual VectorD direction_at(const PointD& point) const override;
    virtual Color intensity(const PointD& point, const Scene& scene) const override;
};

#endif //ifndef AMBIENTLIGHT_H

