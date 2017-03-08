
#ifndef SPHERE_H
#define SPHERE_H

#include "GeometricObject.h"
#include "Intersection.h"
#include "PointD.h"
#include "Ray.h"

/**
 * \brief A Sphere, inplicitly described by it's center point and radius.
 */
class Sphere : public GeometricObject
{
    public:
        Sphere();
        Sphere(const PointD& center, float radius);
        virtual ~Sphere(){};

        virtual const Intersection intersect(const Ray& ray);
    private:
        PointD center;
        float radius;
};


inline Sphere::Sphere()
 : GeometricObject()
 , center(PointD(0.0, 0.0, 0.0))
 , radius(1.0)
{
}

inline Sphere::Sphere(const PointD& center, float radius)
 : GeometricObject()
 , center(center)
 , radius(radius)
{
}

#endif //ifndef SPHERE_H

