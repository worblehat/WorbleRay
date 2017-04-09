#include "PointD3.h"
#include "VectorD.h"


PointD3::PointD3()
    : x(0.0)
    , y(0.0)
    , z(0.0)
{
}

PointD3::PointD3(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z)
{
}

PointD3::PointD3(const VectorD &v)
    : x(v.x)
    , y(v.y)
    , z(v.z)
{
}

PointD3::PointD3(const PointD3 &p)
    : x(p.x)
    , y(p.y)
    , z(p.z)
{
}

std::string PointD3::str() const
{
    std::string x_str = std::to_string(x);
    std::string y_str = std::to_string(y);
    std::string z_str = std::to_string(z);
    return "PointD3(" + x_str + ", " + y_str + ", " + z_str + ")";
}

PointD3 &PointD3::operator=(const PointD3 &p)
{
    if(this != &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    return *this;
}

PointD3 PointD3::operator+(const VectorD &v) const
{
    return PointD3(x + v.x, y + v.y, z + v.z);
}

PointD3 &PointD3::operator+=(const VectorD &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

PointD3 PointD3::operator-(const VectorD &v) const
{
    return PointD3(x - v.x, y - v.y, z - v.z);
}

VectorD PointD3::operator-(const PointD3 &p) const
{
    return VectorD(x - p.x, y - p.y, z - p.z);
}

PointD3 &PointD3::operator-=(const VectorD &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

PointD3 PointD3::operator-()
{
    return PointD3(-x, -y, -z);
}
