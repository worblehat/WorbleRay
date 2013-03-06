/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

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

