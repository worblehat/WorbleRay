#include "PointD.h"
#include "VectorD.h"


PointD::PointD()
    : x(0.0)
    , y(0.0)
    , z(0.0)
{
}

PointD::PointD(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z)
{
}

PointD::PointD(const VectorD &v)
    : x(v.x)
    , y(v.y)
    , z(v.z)
{
}

PointD::PointD(const PointD &p)
    : x(p.x)
    , y(p.y)
    , z(p.z)
{
}

std::string PointD::str() const
{
    std::string x_str = std::to_string(x);
    std::string y_str = std::to_string(y);
    std::string z_str = std::to_string(z);
    return "PointD(" + x_str + ", " + y_str + ", " + z_str + ")";
}

PointD &PointD::operator=(const PointD &p)
{
    if(this != &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    return *this;
}

PointD PointD::operator+(const VectorD &v) const
{
    return PointD(x + v.x, y + v.y, z + v.z);
}

PointD &PointD::operator+=(const VectorD &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

PointD PointD::operator-(const VectorD &v) const
{
    return PointD(x - v.x, y - v.y, z - v.z);
}

VectorD PointD::operator-(const PointD &p) const
{
    return VectorD(x - p.x, y - p.y, z - p.z);
}

PointD &PointD::operator-=(const VectorD &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

PointD PointD::operator-()
{
    return PointD(-x, -y, -z);
}
