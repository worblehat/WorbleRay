
#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Color.h"
#include "Intersection.h"
#include "Light.h"
#include "PointD.h"
#include "VectorD.h"

class PointLight : public Light
{
    public:
        PointLight(const PointD& position = PointD(0.0, 0.0, 0.0),
                    const Color& color = Color(1.0, 1.0, 1.0), 
                    float radiance = 1.0);
        virtual VectorD get_direction(const Intersection& intersection) const;
        virtual Color get_intensity() const;        
    private:
        PointD position;
};
        
inline PointLight::PointLight(const PointD& position, const Color& color, float radiance)
 : Light(color, radiance)
 , position(position)
{
}
        
#endif //ifndef POINTLIGHT_H

