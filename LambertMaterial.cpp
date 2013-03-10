/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#include "LambertMaterial.h"


#include <iostream>
#include <vector>

Color LambertMaterial::shade(const Intersection& intersection, const Scene& scene) const
{
    Color intensity;
    // === Diffuse reflection ===
    Color intensity_diffuse;
    std::vector<Light*>::const_iterator it;
    const std::vector<Light*> lights = scene.get_lights();
    for(it = lights.begin(); it != lights.end(); ++it)
    {
        Color diffuse_light = (*it)->get_intensity(intersection, scene);
        Vector4d n = intersection.get_normal();
        Vector4d l = (*it)->get_direction(intersection);
        intensity_diffuse += diffuse_light * c_diffuse * glm::dot(n, l);
    }
    intensity += intensity_diffuse;

    // === Ambient reflection === 
	Color ambient_light = scene.get_ambient_light()->get_intensity(intersection, scene);
	Color intensity_ambient = ambient_light * c_ambient;
	intensity += intensity_ambient;
   
    return intensity;
}

