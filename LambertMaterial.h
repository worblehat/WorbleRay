/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef LAMBERTMATERIAL_H
#define LAMBERTMATERIAL_H

#include "Color.h"
#include "Material.h"


/*
 * \brief Simple Material that provides a flat and diffuse shading. 
 *
 * Uses the surface normal normal and light vectors to calculate a color value.
 */ 
class LambertMaterial : public Material
{
    public:
        LambertMaterial();
        LambertMaterial(const Color& ambient,const Color& diffuse);

        virtual Color shade(const Intersection& intersection, const Scene& scene) const;
    private:
        Color c_ambient;
        Color c_diffuse;
};

inline LambertMaterial::LambertMaterial()
 : Material()
 , c_ambient(Color(0.5f, 0.5f, 0.5f))
 , c_diffuse(Color(0.5f, 0.5f, 0.5f))
{
}
        
inline LambertMaterial::LambertMaterial(const Color& ambient, const Color& diffuse)
{
    c_ambient = ambient;
    c_diffuse = diffuse; 
}

#endif //ifndef LAMBERTMATERIAL_H

