/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "GeometricObject.h"
#include "mathutil.h"


class GeometricObject; //TODO forward declaration needed?


/**
 * \brief This class represents the result of an intersection test between a Ray and a GeometricObject.
 *
 * Before reading any of the data members you should check if there exists and intersection. 
 * If the intersectino does not exists (i.e. the Ray did not hit the GeometricObject), the 
 * data returned by the other get-functions is undefined.
 *
 * \see Intersection::get_exists()
 */
class Intersection
{
    public:
        Intersection();
        void set_exists(bool exists);
        bool get_exists() const;
        void set_t(double t);
        double get_t() const;
        void set_hit_backside(bool b);
        bool get_hit_backside() const;
        void set_hit_point(const Vector4d& hit_point);
        Vector4d get_hit_point() const; 
        void set_normal(const Vector4d& normal);
        Vector4d get_normal() const;
        void set_hit_object(GeometricObject *object);
        GeometricObject *get_hit_object() const;
    private:
        bool exists;
        bool hit_backside;
        double t;   // Distance from view plane
        Vector4d hit_point;
        Vector4d normal;
        GeometricObject* hit_object;
};

inline Intersection::Intersection()
 : exists(false)
{
}

inline void Intersection::set_exists(bool exists)
{
    this->exists = exists;
}

inline bool Intersection::get_exists() const
{
    return exists;
}

inline void Intersection::set_t(double t)
{
    this->t = t;
}

inline double Intersection::get_t() const
{
    return this->t;
}

inline void Intersection::set_hit_backside(bool b)
{
    hit_backside = b;
}

inline bool Intersection::get_hit_backside() const
{
    return hit_backside;
}
        
inline void Intersection::set_hit_point(const Vector4d& hit_point)
{
    this->hit_point = hit_point;
}

inline Vector4d Intersection::get_hit_point() const
{
    return hit_point;
}

inline void Intersection::set_normal(const Vector4d& normal)
{
    this->normal = normal;
}

inline Vector4d Intersection::get_normal() const
{
    return normal;
}

inline void Intersection::set_hit_object(GeometricObject *object)
{
    hit_object = object;
}
        
inline GeometricObject *Intersection::get_hit_object() const
{
    return hit_object;
}

#endif //ifndef INTERSECTION_H
