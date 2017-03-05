#include "PointD.h"
#include "VectorD.h"

#include <cmath>

VectorD::VectorD()
    : x(1.0)
    , y(0.0)
    , z(1.0)
{
}

VectorD::VectorD(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z)
{
}

VectorD::VectorD(const PointD &p)
    : x(p.x)
    , y(p.y)
    , z(p.z)
{
}

VectorD::VectorD(const VectorD &v)
    : x(v.x)
    , y(v.y)
    , z(v.z)
{
}

VectorD::~VectorD()
{
}

double VectorD::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

double VectorD::dot(const VectorD &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

VectorD VectorD::cross(const VectorD &v) const
{
    return VectorD(y * v.z - z * v.y,
                   z * v.x - x * v.z,
                   x * v.y - y * v.x);
}

void VectorD::normalize()
{
  double len = length();
  if(len > 0)
  {
      x /= len;
      y /= len;
      z /= len;
  }
}

VectorD &VectorD::operator=(const VectorD &v)
{
  if(this != &v)
  {
      x = v.x;
      y = v.y;
      z = v.z;
  }
  return *this;
}

VectorD VectorD::operator+(const VectorD &v) const
{
    return VectorD(x + v.x, y + v.y, z + v.z);
}

VectorD &VectorD::operator+=(const VectorD &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

VectorD VectorD::operator-(const VectorD &v) const
{
    return VectorD(x - v.x, y - v.y, z - v.z);
}

VectorD &VectorD::operator-=(const VectorD &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

VectorD VectorD::operator*(const double &d) const
{
    return VectorD(x * d, y * d, z * d);
}

VectorD &VectorD::operator*=(const double &d)
{
    x *= d;
    y *= d;
    z *= d;
    return *this;
}

VectorD VectorD::operator/(const double &d) const
{
    return VectorD(x / d, y / d, z / d);
}

VectorD &VectorD::operator/=(const double &d)
{
    x /= d;
    y /= d;
    z /= d;
    return *this;
}

VectorD VectorD::operator-()
{
  return VectorD(-x, -y, -z);
}

VectorD operator*(const double &d, const VectorD &v)
{
    return v * d;
}
