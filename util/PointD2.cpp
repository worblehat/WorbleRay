#include "PointD2.h"

PointD2::PointD2()
    : x(0.0)
    , y(0.0)
{

}

PointD2::PointD2(double x, double y)
    : x(x)
    , y(y)
{

}

std::string PointD2::str() const
{
    std::string x_str = std::to_string(x);
    std::string y_str = std::to_string(y);
    return "PointD2(" + x_str + ", " + y_str + ")";
}
