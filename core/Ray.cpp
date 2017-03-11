#include "Ray.h"


Ray::Ray()
    : origin(0.0, 0.0, 0.0)
    , direction(0.0, 0.0, 1.0)
{
}

Ray::Ray(const PointD& origin, const VectorD& direction)
    : origin(origin)
    , direction(direction)
{
}

Ray::Ray(const double& o_x, const double& o_y, const double& o_z,
                const double& d_x, const double& d_y, const double& d_z)
    : origin(o_x, o_y, o_z)
    , direction(d_x, d_y, d_z)
{
}
