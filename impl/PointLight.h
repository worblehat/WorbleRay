#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Color.h"
#include "Light.h"
#include "PointD3.h"


class PointLight : public Light
{
public:
    PointLight(const PointD3& position = PointD3(0.0, 0.0, 0.0),
               const Color& color = Color(1.0, 1.0, 1.0),
               float radiance = 1.0);
    virtual VectorD direction_at(const PointD3& point) const override;
    virtual Color intensity(const PointD3& point, const Scene& scene) const override;
private:
    PointD3 position;
};

#endif //ifndef POINTLIGHT_H

