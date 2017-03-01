
#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Color.h"
#include "Intersection.h"
#include "Light.h"
#include "mathutil.h"

class PointLight : public Light
{
    public:
        PointLight(const Vector4d& position = Vector4d(0.0, 0.0, 0.0, 1.0), 
                    const Color& color = Color(1.0, 1.0, 1.0), 
                    float radiance = 1.0);
        virtual Vector4d get_direction(const Intersection& intersection) const; 
        virtual Color get_intensity() const;        
    private:
        Vector4d position;
};
        
inline PointLight::PointLight(const Vector4d& position, const Color& color, float radiance)
 : Light(color, radiance)
 , position(position)
{
}
        
#endif //ifndef POINTLIGHT_H

