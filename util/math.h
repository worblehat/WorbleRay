#ifndef MATH_H
#define MATH_H

#include <cmath>

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

    inline double next_power_of_two(double x)
    {
        short result = 1;
        while(result < x)
        {
            result *= 2;
        }
        return result;
    }

    inline double next_smaller_square_number(double x)
    {
        double root = std::sqrt(x);
        int floor = static_cast<int>(root);
        return floor * floor;
    }
}
#endif // MATH_H
