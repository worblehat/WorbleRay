/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"
#include "Intersection.h"
#include "Scene.h"

//TODO fortward declaration necessary here?
class Scene;

/**
 * \brief Abstract base class for Materials that are able to shade an intersection point.
 */
class Material
{
    public:
        virtual ~Material(){};
        virtual Color shade(const Intersection& intersection, const Scene& scene) const = 0;
};

#endif //ifndef MATERIAL_H
