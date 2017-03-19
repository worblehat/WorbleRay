#ifndef LIGHT_H
#define LIGHT_H

#include "Color.h"

class PointD;
class Scene;
class VectorD;


/**
 * \brief Abstract base class for lights.
 */
class Light
{
public:
    Light();
    Light(const Color& color, float radiance = 1.0);
    virtual ~Light() = default;
    /**
     * \brief Get the normalized incomming direction of the light at a point.
     * Used as "light vector" in shading calculations."
     */
    virtual VectorD direction_at(const PointD& point) const = 0;
    virtual Color intensity(const PointD& point, const Scene& scene) const = 0;
    virtual void set_radiance(float r);
    virtual void set_color(const Color& c);
protected:
    float radiance;
    Color color;
};

#endif //ifndef LIGHT_H
