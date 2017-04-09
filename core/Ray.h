#ifndef RAY_H
#define RAY_H

#include "PointD3.h"
#include "VectorD.h"


/**
 * \brief Ray used by the ray tracer and defined by it's origin and direction.
 */
class Ray {
public:
    Ray();
    Ray(const PointD3& origin, const VectorD& direction);
    Ray(const double& o_x, const double& o_y, const double& o_z,
        const double& d_x, const double& d_y, const double& d_z);

public:
    PointD3 origin;
    VectorD direction;
    // 0: primary ray, 1: first reflection, 2: second reflection ...
    unsigned short recursion_depth;
};

#endif //ifndef RAY_H
