#ifndef POINTD3_H
#define POINTD3_H

#include <string>

class VectorD;


/**
 * @brief Three-dimensional point with double precision floating-point coordinates.
 */
class PointD3
{
public:
    PointD3();
    PointD3(double x, double y, double z);
    explicit PointD3(const VectorD &v);
    PointD3(const PointD3 &p);

    std::string str() const;

    //! point = point
    PointD3 &operator=(const PointD3 &p);
    //! point = point + vector
    PointD3 operator+(const VectorD &v) const;
    //! point += vector
    PointD3 &operator+=(const VectorD &v);
    //! point = point - vector
    PointD3 operator-(const VectorD &v) const;
    //! vector = point - point
    VectorD operator-(const PointD3 &p) const;
    //! point -= vector
    PointD3 &operator-=(const VectorD &v);
    //! point = -point
    PointD3 operator-();

public:
    double x;
    double y;
    double z;
};

#endif // POINTD3_H
