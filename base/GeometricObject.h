#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include <memory>

class Intersection;
class Material; 
class Ray; 


/**
 * \brief Abstract base class for geometric objects that can be rendered to the screen.
 *
 * A GeometricObject has an oriented surface that can be hit by a ray. Intersection points between
 * a ray and the object can be shaded using the object's material.
 */
class GeometricObject
{
public:
    virtual ~GeometricObject() = default;
    virtual const Intersection intersect(const Ray& ray) = 0;
    virtual void set_material(std::shared_ptr<Material> material);
    virtual const Material *material() const;
protected:
    std::shared_ptr<Material> _material;
};

#endif // ifndef GEOMETRIC_OBJECT_H
