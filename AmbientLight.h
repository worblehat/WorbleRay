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

#include "Color.h"
#include "Intersection.h"
#include "Light.h"
#include "mathutil.h"
#include "Scene.h"

class Intersection;
class Light;
class Scene;


/**
 * \brief Ambient light source without position and direction.
 */
class AmbientLight : public Light
{
    public:
        AmbientLight();
        AmbientLight(const Color& color, float radiance = 1.0);
        virtual Vector4d get_direction(const Intersection& intersection) const; 
        virtual Color get_intensity(const Intersection& intersection, const Scene& scene) const;
};

#endif //ifndef AMBIENTLIGHT_H

