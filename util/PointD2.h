#ifndef POINTD2_H
#define POINTD2_H

#include <string>


/**
 * @brief Two-dimensional point with double precision floating-point coordinates.
 */
class PointD2
{
public:
    PointD2();
    PointD2(double x, double y);
    PointD2(const PointD2 &p);

    //! point = point
    PointD2 &operator=(const PointD2 &p);

    std::string str() const;

public:
    double x;
    double y;
};

#endif // POINTD2_H
