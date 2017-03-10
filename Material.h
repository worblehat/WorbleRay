#ifndef MATERIAL_H
#define MATERIAL_H

class Color;
class Intersection;
class Scene;


/**
 * \brief Abstract base class for materials that are able to calculate the shading of an
 *        object at a ray-intersection point.
 */
class Material
{
public:
    virtual ~Material() = default;
    virtual Color shade(const Intersection& intersection, const Scene& scene) const = 0;
};

#endif //ifndef MATERIAL_H
