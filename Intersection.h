
#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "PointD.h"
#include "Ray.h"
#include "VectorD.h"

class GeometricObject;

/**
 * \brief This class represents the result of an intersection test between a Ray and a GeometricObject.
 *
 * Before reading any of the data members you should check if there exists an intersection. 
 * If the intersection does not exists (i.e. the Ray did not hit the GeometricObject), the 
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
        void set_hit_point(const PointD& hit_point);
        PointD get_hit_point() const;
        void set_normal(const VectorD& normal);
        VectorD get_normal() const;
        void set_hit_object(GeometricObject *object);
        GeometricObject *get_hit_object() const;
        void set_incident_ray(const Ray& ray);
        const Ray& get_incident_ray();
    private:
        bool exists;
        double t;   // Distance from view plane / ray origin (TODO needed?)
        Ray incident_ray; // Ray that intersects with the object
        PointD hit_point;
        VectorD normal;    // Normalized surface normal at hit point
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
        
inline void Intersection::set_hit_point(const PointD& hit_point)
{
    this->hit_point = hit_point;
}

inline PointD Intersection::get_hit_point() const
{
    return hit_point;
}

inline void Intersection::set_normal(const VectorD& normal)
{
    this->normal = normal;
    this->normal.normalize();
}

inline VectorD Intersection::get_normal() const
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
        
inline void Intersection::set_incident_ray(const Ray& ray)
{
    incident_ray = ray;
}
        
inline const Ray& Intersection::get_incident_ray()
{
    return incident_ray;
}


#endif //ifndef INTERSECTION_H
