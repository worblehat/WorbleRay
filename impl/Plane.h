#ifndef PLANE_H
#define PLANE_H

#include "GeometricObject.h"
#include "PointD.h"
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
    virtual ~Plane();

    virtual const Intersection intersect(const Ray& ray);
private:
    PointD center;
    VectorD normal;
};

#endif //ifndef PLANE_H
