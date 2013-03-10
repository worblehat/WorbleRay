/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Color.h"
#include "Intersection.h"
#include "mathutil.h"
#include "Scene.h"

class Intersection;
class Scene;    //TODO needed?

/**
 * \brief Abstract base class for lights.
 */
class Light
{
    public:
        Light();
        Light(const Color& color, float radiance = 1.0);
        virtual ~Light(){};
        /**
         * Get the normalized direction, used as "light vector" in shading calculations."
         */
        virtual Vector4d get_direction(const Intersection& intersection) const = 0; 
        virtual Color get_intensity(const Intersection& intersection, const Scene& scene) const = 0;        
        virtual void set_radiance(float r);
        virtual void set_color(const Color& c);
    protected:
        float radiance;
        Color color;
};

inline Light::Light()
 : color(Color(1.0, 1.0, 1.0))
, radiance(1.0)
{
}

inline Light::Light(const Color& color, float radiance)
 : color(color)
 , radiance(radiance)
{
}

inline void Light::set_radiance(float r)
{
    radiance = r;
}     

inline void Light::set_color(const Color& c)
{
    color = c;
}

#endif //ifndef LIGHT_H
