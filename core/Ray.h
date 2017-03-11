#ifndef RAY_H
#define RAY_H

#include "PointD.h"
#include "VectorD.h"


/**
 * \brief Ray used by the ray tracer and defined by it's origin and direction.
 */
class Ray {
public:
    Ray();
    Ray(const PointD& origin, const VectorD& direction);
    Ray(const double& o_x, const double& o_y, const double& o_z,
        const double& d_x, const double& d_y, const double& d_z);

public:
    PointD origin;
    VectorD direction;
};

#endif //ifndef RAY_H
