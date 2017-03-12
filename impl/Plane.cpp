#include "Intersection.h"
#include "Plane.h"
#include "Ray.h"


Plane::Plane()
    : GeometricObject()
    , point(PointD(0.0, 0.0, 0.0))
    , normal(VectorD(0.0, 1.0, 0.0))
{
}

Plane::Plane(const PointD& point ,const VectorD& normal)
    : GeometricObject()
    , point(point)
    , normal(normal)
{
}

const Intersection Plane::intersect(const Ray& ray)
{
    /*
     * A plane can be implicitly described by (q - p) * n = 0,
     * where q and p are two points in the plane and n is its normal.
     * Subsituting q by the ray ewuation o + td yields (o + td - p) * n = 0.
     * The only unkown variable is t. As this is a linear equation there is a
     * single solution given by t = (p - o) * n / (d * n). This solution yields
     * the intersection point between the ray and the plane.
     */
    double t = (point - ray.origin).dot(normal) / ray.direction.dot(normal);

    Intersection intersection;
    if (t > 0) {
        intersection.normal = normal;
        intersection.hit_point = ray.origin + t * ray.direction;
        intersection.exists = true;
        intersection.hit_object = this;
        intersection.t = t;
    }

    return intersection;
}

