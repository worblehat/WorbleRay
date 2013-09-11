/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Color.h"
#include "Intersection.h"
#include "Light.h"
#include "mathutil.h"
#include "Scene.h"

class PointLight : public Light
{
    public:
        PointLight(const Vector4d& position = Vector4d(0.0, 0.0, 0.0, 1.0), 
                    const Color& color = Color(1.0, 1.0, 1.0), 
                    float radiance = 1.0);
        virtual Vector4d get_direction(const Intersection& intersection) const; 
        virtual Color get_intensity(const Intersection& intersection, const Scene& scene) const;        
    private:
        Vector4d position;
};
        
inline PointLight::PointLight(const Vector4d& position, const Color& color, float radiance)
 : Light(color, radiance)
 , position(position)
{
}
        
#endif //ifndef POINTLIGHT_H

