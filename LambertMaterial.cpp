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

#include "AmbientLight.h"
#include "Light.h"

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
        Vector4d n = intersection.get_normal();
        Vector4d l = -1 * (*it)->get_direction(intersection);
        float dot = glm::dot(n, l);
        if(dot > 0.0f) 
        {
            Color diffuse_light = (*it)->get_intensity();
            intensity_diffuse += diffuse_light * c_diffuse * dot;
        }
    }
    intensity += intensity_diffuse;

    // === Ambient reflection === 
	Color ambient_light = scene.get_ambient_light()->get_intensity();
	Color intensity_ambient = ambient_light * c_ambient;
	intensity += intensity_ambient;
   
    return intensity;
}

