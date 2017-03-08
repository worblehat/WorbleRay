#ifndef VECTORD_H
#define VECTORD_H

class PointD;

/**
 * @brief Three-dimensional vector (representing a direction) with double precision floating-point
 * coordinates.
 */
class VectorD
{
public:
    VectorD();
    VectorD(double x, double y, double z);
    VectorD(const PointD &p);
    VectorD(const VectorD &v);

    virtual ~VectorD();

    double length() const;
    //! Dot-product
    double dot(const VectorD &v) const;
    //! Cross-product
    VectorD cross(const VectorD &v) const;
    //! Normalize this vector
    void normalize();
    //! vector = vector
    VectorD &operator=(const VectorD &v);
    //! vector = vector + vector
    VectorD operator+(const VectorD &v) const;
    //! vector += vector
    VectorD &operator+=(const VectorD &v);
    //! vector = vector - vector
    VectorD operator-(const VectorD &v) const;
    //! vector -= vector
    VectorD &operator-=(const VectorD &v);
    //! vector = vector * double
    VectorD operator*(const double &d) const;
    //! vector *= double
    VectorD &operator*=(const double &d);
    //! vector = vector / double
    VectorD operator/(const double &d) const;
    //! vector /= double
    VectorD &operator/=(const double &d);
    //! vector = -vector
    VectorD operator-() const;

public:
    double x;
    double y;
    double z;
};

//! vector = double * vector
VectorD operator*(const double &d, const VectorD &v);

#endif // VECTORD_H
