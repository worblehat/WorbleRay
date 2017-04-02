#ifndef DISK_H
#define DISK_H

#include "GeometricObject.h"
#include "PointD.h"
#include "VectorD.h"


/** \brief A flat disk defined by its center, radius and normal.
 *
 */
class Disk : public GeometricObject
{
public:
    Disk();
    Disk(const PointD& center, float radius, const VectorD& normal);

    virtual const Intersection intersect(const Ray& ray) const override;
private:
    PointD center;
    float radius;
    VectorD normal;
};

#endif // DISK_H
