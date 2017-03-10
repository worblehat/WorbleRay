#include "Intersection.h"
#include "Plane.h"
#include "Ray.h"


Plane::Plane()
    : GeometricObject()
    , center(PointD(0.0, 0.0, 0.0))
    , normal(VectorD(0.0, 1.0, 0.0))
{
}

Plane::Plane(const PointD& center ,const VectorD& normal)
    : GeometricObject()
    , center(center)
    , normal(normal)
{
}

Plane::~Plane()
{
}

const Intersection Plane::intersect(const Ray& ray)
{
    Intersection intersection;
    //TODO NEXT
    intersection.hit_object = this;
    intersection.exists = false;
    return intersection;
}

