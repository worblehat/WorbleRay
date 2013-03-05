/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include "Intersection.h"
#include "Ray.h"

class GeometricObject
{
    public:
        virtual const Intersection& intersect(const Ray& ray);
};

#endif // ifndef GEOMETRIC_OBJECT_H
