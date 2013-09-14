/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

class Intersection;
class Material; 
class Ray; 

/**
 * \brief Abstract base class for geometric objects that can be rendered to the screen.
 *
 * A GeometricObject has an oriented surface that can be hit by a ray. Intersection points between a ray
 * and the object can be shaded using the objects's material.
 */
class GeometricObject
{
    public:
        virtual ~GeometricObject(){};
        virtual const Intersection intersect(const Ray& ray) = 0;
        virtual void set_material(Material const *material);
        virtual Material const *get_material() const;
    protected:
        Material const *material;
};

inline void GeometricObject::set_material(Material const *material)
{
    this->material = material;
} 

inline Material const *GeometricObject::get_material() const
{
    return material;
}

#endif // ifndef GEOMETRIC_OBJECT_H
