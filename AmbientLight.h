#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "Light.h"

class Color;
class Intersection;
class VectorD;


/**
 * \brief Ambient light source without position and direction.
 */
class AmbientLight : public Light
{
public:
    AmbientLight();
    explicit AmbientLight(const Color& color, float radiance = 1.0);
    virtual VectorD direction_at(const Intersection& intersection) const override;
    virtual Color intensity() const override;
};

#endif //ifndef AMBIENTLIGHT_H

