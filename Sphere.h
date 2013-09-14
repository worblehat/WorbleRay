/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "GeometricObject.h"
#include "Intersection.h"
#include "mathutil.h"
#include "Ray.h"

/**
 * \brief A Sphere, inplicitly described by it's center point and radius.
 */
class Sphere : public GeometricObject
{
    public:
        Sphere();
        Sphere(const Vector4d& center, float radius);
        virtual ~Sphere(){};

        virtual const Intersection intersect(const Ray& ray);
    private:
        Vector4d center;
        float radius;
};


inline Sphere::Sphere()
 : GeometricObject()
 , center(Vector4d(0.0, 0.0, 0.0, 1.0))
 , radius(1.0)
{
}

inline Sphere::Sphere(const Vector4d& center, float radius)
 : GeometricObject()
 , center(center)
 , radius(radius)
{
}

#endif //ifndef SPHERE_H

