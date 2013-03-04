#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include "Intersection.h"
#include "Ray.h"

class GeometricObject
{
    public:
        virtual const Intersection& intersect(const Ray& ray);
};

#endif // ifndef GEOMETRIC_OBJECT_H
