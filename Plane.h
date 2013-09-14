/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef PLANE_H
#define PLANE_H

#include "GeometricObject.h"
#include "Intersection.h"
#include "mathutil.h"
#include "Ray.h"


/**
 * \brief An infinite plane.
 *
 * The plane is defined by it's center point and normal.
 */ 
class Plane : public GeometricObject
{
    public:
        Plane();
        Plane(const Vector4d& center, const Vector4d& normal);
        virtual ~Plane(){};

        virtual const Intersection intersect(const Ray& ray);
    private:
        Vector4d center;
        Vector4d normal; 
};


inline Plane::Plane()
 : GeometricObject()
 , center(Vector4d(0.0, 0.0, 0.0, 1.0))
 , normal(Vector4d(0.0, 1.0, 0.0, 0.0))
{
}

inline Plane::Plane(const Vector4d& center ,const Vector4d& normal)
 : GeometricObject()
 , center(center)
 , normal(normal)
{ 
}

#endif //ifndef PLANE_H
