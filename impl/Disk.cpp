#include "Disk.h"
#include "Intersection.h"
#include "Ray.h"

#include <cmath>


Disk::Disk()
    : center(0.0, 0.0, 0.0)
    , radius(100.0f)
    , normal(0.0, 1.0, 0.0)
{

}

Disk::Disk(const PointD3& center, float radius, const VectorD& normal)
    : center(center)
    , radius(radius)
    , normal(normal)
{

}

const Intersection Disk::intersect(const Ray& ray) const
{
    // Plane interscetion (see Plane.cpp)
    double t = (center - ray.origin).dot(normal) / ray.direction.dot(normal);

    Intersection intersection;
    intersection.incident_ray = ray;
    if (t > 0) {
        // Check if hit-point is inside the disk's radius
        PointD3 hit_point = ray.origin + t * ray.direction;
        // Working with squared distance, to avoid applying square root
        double radius_squared = std::pow(radius, 2);
        if((center - hit_point).length_squared() <= radius_squared)
        {
            intersection.normal = normal;
            intersection.hit_point = hit_point;
            intersection.exists = true;
            intersection.hit_object = this;
            intersection.t = t;
        }
    }

    return intersection;
}
