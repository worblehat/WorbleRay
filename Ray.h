
#ifndef RAY_H
#define RAY_H

#include "PointD.h"
#include "VectorD.h"

/**
 * \brief Ray used by the ray tracer and defined by it's origin and direction.
 */
class Ray {
    public:
        Ray();
        Ray(const PointD& origin, const VectorD& direction);
        Ray(const double& o_x, const double& o_y, const double& o_z, 
                const double& d_x, const double& d_y, const double& d_z);

        const PointD& get_origin() const;
        void set_origin(const PointD& origin);
        const VectorD& get_direction() const;
        void set_direction(const VectorD& direction);

    private:
        PointD origin;
        VectorD direction;
};


inline Ray::Ray()
 : origin(0.0, 0.0, 0.0)
 , direction(0.0, 0.0, 1.0)
{
}

inline Ray::Ray(const PointD& origin, const VectorD& direction)
 : origin(origin)
 , direction(direction)
{
}

inline Ray::Ray(const double& o_x, const double& o_y, const double& o_z, 
            const double& d_x, const double& d_y, const double& d_z)
 : origin(o_x, o_y, o_z)
 , direction(d_x, d_y, d_z)
{
}

inline const PointD& Ray::get_origin() const
{
    return origin;
}

inline void Ray::set_origin(const PointD& origin)
{
    this->origin = origin; 
}   
        
inline const VectorD& Ray::get_direction() const
{
    return direction;
}

inline void Ray::set_direction(const VectorD& direction)
{
    this->direction = direction;
}

#endif //ifndef RAY_H
