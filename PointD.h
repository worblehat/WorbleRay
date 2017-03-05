#ifndef POINTD_H
#define POINTD_H

class VectorD;

/**
 * @brief Three-dimensional point with double precision floating-point coordinates.
 */
class PointD
{
public:
    PointD();
    PointD(double x, double y, double z);
    explicit PointD(const VectorD &v);
    PointD(const PointD &p);

    virtual ~PointD();

    //! point = point
    PointD &operator=(const PointD &p);
    //! point = point + vector
    PointD operator+(const VectorD &v) const;
    //! point += vector
    PointD &operator+=(const VectorD &v);
    //! point = point - vector
    PointD operator-(const VectorD &v) const;
    //! vector = point - point
    VectorD operator-(const PointD &p) const;
    //! point -= vector
    PointD &operator-=(const VectorD &v);
    //! point = -point
    PointD operator-();

public:
    double x;
    double y;
    double z;
};

#endif // POINTD_H
