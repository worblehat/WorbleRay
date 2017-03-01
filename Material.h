
#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"

class Scene;
class Intersection;

/**
 * \brief Abstract base class for Materials that are able to shade an intersection point.
 */
class Material
{
    public:
        virtual ~Material(){};
        virtual Color shade(const Intersection& intersection, const Scene& scene) const = 0;
};

#endif //ifndef MATERIAL_H
