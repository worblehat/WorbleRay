#ifndef PLANE_H
#define PLANE_H

#include "GeometricObject.h"
#include "PointD.h"
#include "VectorD.h"


/**
 * \brief An infinite plane.
 *
 * The plane is defined by an arbitrary point in the plane and the normal.
 */
class Plane : public GeometricObject
{
public:
    Plane();
    Plane(const PointD& point, const VectorD& normal);

    virtual const Intersection intersect(const Ray& ray) const override;
private:
    PointD point;
    VectorD normal;
};

#endif //ifndef PLANE_H
