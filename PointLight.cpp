/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#include "PointLight.h"


Vector4d PointLight::get_direction(const Intersection& intersection) const
{
    return glm::normalize(Vector4d(intersection.get_hit_point() - position));
}

Color PointLight::get_intensity(const Intersection& intersection, const Scene& scene) const
{
    return color * radiance;
}

