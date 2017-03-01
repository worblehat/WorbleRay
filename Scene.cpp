
#include "Scene.h"

#include <limits>


Intersection Scene::trace(const Ray& ray)
{
    double t_min = std::numeric_limits<double>::max();
    Intersection closest_intersection;
    closest_intersection.set_exists(false);

    std::vector<GeometricObject*>::const_iterator it;
    for(it = objects.begin(); it != objects.end(); ++it)
    {
        Intersection intersection = (*it)->intersect(ray); 
        if(intersection.get_exists() && (intersection.get_t() < t_min))
        {
            closest_intersection = intersection;  
        }
    }

    return closest_intersection;
}

