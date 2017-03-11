#ifndef MATH_H
#define MATH_H

namespace math
{
    // π
    const double pi = 3.141592653589793;
    // π/180 rad = 1°
    const double pi_180 = 0.017453292519943;
    // 180/π° = 1 rad
    const double _180_pi = 57.295779513082321;

    inline double to_radian(double degree)
    {
        return degree * pi_180;
    }

    inline double to_degree(double radian)
    {
        return radian * _180_pi;
    }
}
#endif // MATH_H
