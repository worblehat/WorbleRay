
#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "Color.h"
#include "Intersection.h"
#include "Light.h"
#include "VectorD.h"

/**
 * \brief Ambient light source without position and direction.
 */
class AmbientLight : public Light
{
    public:
        AmbientLight();
        AmbientLight(const Color& color, float radiance = 1.0);
        virtual VectorD get_direction(const Intersection& intersection) const;
        virtual Color get_intensity() const;
};

#endif //ifndef AMBIENTLIGHT_H

