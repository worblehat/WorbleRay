#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "PointD.h"
#include "Ray.h"
#include "VectorD.h"

class GeometricObject;


/**
 * \brief This class represents the result of an intersection test between a Ray and a
 *        GeometricObject.
 *
 * Before reading any of the data members you should check if there exists an intersection.
 * If the intersection does not exists (i.e. the Ray did not hit the GeometricObject), the
 * data returned by the other get-functions is undefined.
 *
 * \see Intersection::get_exists()
 */
class Intersection
{
public:
    Intersection();
public:
    bool exists;
    double t; //TODO needed?
    Ray incident_ray;
    PointD hit_point;
    VectorD normal;
    const GeometricObject *hit_object;
};

#endif //ifndef INTERSECTION_H
