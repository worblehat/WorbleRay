#ifndef SPHERE_H
#define SPHERE_H

#include "GeometricObject.h"
#include "PointD.h"


/**
 * \brief A Sphere, inplicitly described by it's center point and radius.
 */
class Sphere : public GeometricObject
{
public:
    Sphere();
    Sphere(const PointD& center, float radius);

    virtual const Intersection intersect(const Ray& ray);
private:
    PointD center;
    float radius;
};

#endif //ifndef SPHERE_H

