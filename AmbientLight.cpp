/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#include "AmbientLight.h"


AmbientLight::AmbientLight()
: Light(Color(1.0, 1.0, 1.0), 1.0f)
{
}

AmbientLight::AmbientLight(const Color& color, float radiance)
 : Light(color, radiance)
{
}

Vector4d AmbientLight::get_direction(const Intersection& intersection) const
{
    return Vector4d(0.0, 0.0, 0.0, 0.0);
}

Color AmbientLight::get_intensity(const Intersection& intersection, const Scene& scene) const
{
    return color * radiance;
}

