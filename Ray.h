/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef RAY_H
#define RAY_H

#include "mathutil.h"

#include <glm/glm.hpp>

/**
 * \brief Ray used by the ray tracer and defined by it's origin and direction.
 */
class Ray {
    public:
        Ray();
        Ray(const Vector4d& origin, const Vector4d& direction);
        Ray(const double& o_x, const double& o_y, const double& o_z, 
                const double& d_x, const double& d_y, const double& d_z);

        const Vector4d& get_origin() const;
        void set_origin(const Vector4d& origin);
        const Vector4d& get_direction() const;
        void set_direction(const Vector4d& direction);

    private:
        Vector4d origin;
        Vector4d direction;
};


inline Ray::Ray()
 : origin(0.0, 0.0, 0.0, 1.0)
 , direction(0.0, 0.0, 1.0, 0.0)
{
}

inline Ray::Ray(const Vector4d& origin, const Vector4d& direction)
 : origin(origin)
 , direction(direction)
{
}

inline Ray::Ray(const double& o_x, const double& o_y, const double& o_z, 
            const double& d_x, const double& d_y, const double& d_z)
 : origin(o_x, o_y, o_z, 1.0)
 , direction(d_x, d_y, d_z, 0.0)
{
}

inline const Vector4d& Ray::get_origin() const
{
    return origin;
}

inline void Ray::set_origin(const Vector4d& origin)
{
    this->origin = origin; 
}   
        
inline const Vector4d& Ray::get_direction() const
{
    return direction;
}

inline void Ray::set_direction(const Vector4d& direction)
{
    this->direction = direction;
}

#endif //ifndef RAY_H
