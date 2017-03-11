#include "Intersection.h"
#include "Ray.h"
#include "Sphere.h"
#include "VectorD.h"

#include <cmath>


Sphere::Sphere()
    : GeometricObject()
    , center(PointD(0.0, 0.0, 0.0))
    , radius(1.0)
{
}

Sphere::Sphere(const PointD& center, float radius)
    : GeometricObject()
    , center(center)
    , radius(radius)
{
}

const Intersection Sphere::intersect(const Ray& ray)
{
    /*
     * An intersection between a ray and sphere can be described by two different formulas, which
     * are therefore equivalent:
     * Ray.origin + t * Ray.direction = Sphere.center + q
     * where q is a vector from the spheres center to the sphere surface with length = Sphere.radius
     * This forumla can be rearranged to a quadratic equation for t:
     * a * t² + b * t + c = 0
     * where
     * a = Ray.direction * Ray.direction    (if direction is normalized: a = 1)
     * b = 2 * Ray.direction * (Ray.origin - Sphere.center)
     * c = (Ray.origin - Sphere.center) * (Ray.origin - Sphere.center) - (Sphere.radius)^2
     * Solving the quation for t yields:
     * t = (-b +- sqrt(b² - 4ac)) / (2a)
     * Only the following part is interesting in order to determine how many intersection points
     * exist:
     * d = b² - 4ac
     * d < 0: no intersection
     * d = 0: one intersection
     * d > 0: two intersections
     * Only if d >= 0 we need to calculate t to check if the ray starts before, inside or after the
     * sphere.
     */

    Intersection intersection;
    intersection.exists = false;
    intersection.incident_ray = ray;
    double t;
    PointD r_o = ray.origin;
    VectorD r_d = ray.direction;

    // Precalculations
    VectorD ray_sphere_diff = r_o - center;
    double a = r_d.dot(r_d);
    double b = 2 * r_d.dot(ray_sphere_diff);
    double c = ray_sphere_diff.dot(ray_sphere_diff) - std::pow(radius, 2);
    double d = std::pow(b, 2) - 4 * a * c;

    // No intersection
    if(d < 0)
    {
        return intersection;
    }

    double sqrt_d = std::sqrt(d);
    // First intersection point
    t = (- b - sqrt_d) / (2 * a);
    // Ray origin "before" sphere?
    if(t > 0)
    {
        intersection.hit_object = this;
        intersection.exists = true;
        intersection.t = t;
        intersection.hit_point = r_o + t * r_d;
        intersection.normal = intersection.hit_point - center;
        intersection.normal.normalize();
    }
    // if t1 was <= 0 we check the second intersection point (if there is one)
    else if(d > 0)
    {
        // Second intersection point
        t = (- b + sqrt_d) / (2 * a);
        if(t > 0)
        {
            // The ray's origin is inside the sphere...
            // TODO This intersection point might be interesting for refractions.
        }
    }

    return intersection;
}

