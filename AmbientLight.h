/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "Light.h"


/**
 * \brief Ambient light source without position and direction.
 */
class AmbientLight : public Light
{
    public:
        AmbientLight();
        AmbientLight(const Color& color, float radiance = 1.0);
        virtual Color calc_intensity() const;        
        void set_radiance(float r);
        void set_color(const Color& c);
    private:
        float radiance;
        Color color;
};

inline AmbientLight::AmbientLight()
 : Light()
 , color(Color(1.0, 1.0, 1.0))
 , radiance(1.0)
{
}

inline AmbientLight::AmbientLight(const Color& color, float radiance)
 : Light()
{
    this->color = color;
    this->radiance = radiance;
}

inline void AmbientLight::set_radiance(float r)
{
    radiance = r;
}     

inline void AmbientLight::set_color(const Color& c)
{
    color = c;
}

inline Color AmbientLight::calc_intensity() const
{
    return color * radiance;
}

#endif //ifndef AMBIENTLIGHT_H

