
#include "Sphere.h"

#include <cmath>
#include <iostream>

const Intersection Sphere::intersect(const Ray& ray)
{
    /*
     * An intersection between a ray and sphere can be described by two different vector paths, which
     * are therefore equal:
     * Ray.origin + t * Ray.direction = Sphere.center + Q
     * where Q is a vector from the spheres center to the sphere surface with length = Sphere.radius 
     * This forumla can be rearranged to a quadratic equation for t:
     * a * t^1 + b * t + c = 0
     * where
     * a = Ray.direction * Ray.direction    (if direction is normalized: a = 1)
     * b = 2 * Ray.direction * (Ray.origin - Sphere.center)
     * c = (Ray.origin - Sphere.center) * (Ray.origin - Sphere.center) - (Sphere.radius)^2
     * After solving the quation for t to
     * t = (-b +- sqrt(b^2 -4ac)) / (2a)
     * only the following part of it's determinant is interesting to
     * determine how many intersection points exist:
     * d = b^2 - 4ac
     * d < 0: no intersection
     * d = 0: one intersection
     * d > 0: two intersections 
     * If d >= 0 we need to calculate t to check if the ray starts before, inside or after the sphere.
     */

    Intersection intersection;
    intersection.set_exists(false);
    intersection.set_incident_ray(ray);
    double t;
    double radius = this->radius; 
    Vector4d origin = ray.get_origin();
    Vector4d center = this->center; 
    Vector4d dir = ray.get_direction();
    // Precalculations
    Vector4d ray_sphere_diff = origin - center; 
    double a = glm::dot(dir, dir);
    double b = 2 * glm::dot(dir, ray_sphere_diff);
    double c = glm::dot(ray_sphere_diff, ray_sphere_diff) - std::pow(radius, 2);
    double d = std::pow(b, 2) - 4 * a * c;
    // At least one intersection 
    if(d >= 0)
    {
        double sqrt_d = std::sqrt(d);
        // First intersection point
        t = (- b - sqrt_d) / (2 * a);
        // ray origin "before" sphere?
        if(t > 0) // TODO include a small offset (epsilon) here *or* when calculating intersections for shadows
        {
            intersection.set_hit_object(this);
            intersection.set_exists(true);
            intersection.set_t(t);
            // Calculate intersection point
            Vector4d hit_point = origin + t * dir;
            intersection.set_hit_point(hit_point);
            // Calculate normal at intersection point
            intersection.set_normal(hit_point - center); //TODO Test!
            //TODO normalize normal?
        }
        // if t1 was <= 0 we check the second intersection point (if there is one) 
        else if(d > 0)
        {
            t = (- b + sqrt_d) / (2 * a);
            if(t > 0)
            {
                // The ray's origin is inside the sphere...
                //TODO The ray hits the sphere on it's inside, so this intersection point my only
                // be interesting for refractions. 
            }
        } 
    }
    
    return intersection;
}

