
#ifndef PLANE_H
#define PLANE_H

#include "GeometricObject.h"
#include "Intersection.h"
#include "PointD.h"
#include "Ray.h"
#include "VectorD.h"


/**
 * \brief An infinite plane.
 *
 * The plane is defined by it's center point and normal.
 */ 
class Plane : public GeometricObject
{
    public:
        Plane();
        Plane(const PointD& center, const VectorD& normal);
        virtual ~Plane(){};

        virtual const Intersection intersect(const Ray& ray);
    private:
        PointD center;
        VectorD normal;
};


inline Plane::Plane()
 : GeometricObject()
 , center(PointD(0.0, 0.0, 0.0))
 , normal(VectorD(0.0, 1.0, 0.0))
{
}

inline Plane::Plane(const PointD& center ,const VectorD& normal)
 : GeometricObject()
 , center(center)
 , normal(normal)
{ 
}

#endif //ifndef PLANE_H
