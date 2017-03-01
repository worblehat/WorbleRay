
#include "Plane.h"


const Intersection Plane::intersect(const Ray& ray)
{
    Intersection intersection;
    //TODO NEXT
    intersection.set_hit_object(this);
    intersection.set_exists(false);
    return intersection;
}

