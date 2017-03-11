#include "GeometricObject.h"


void GeometricObject::set_material(std::shared_ptr<Material> material)
{
    _material = material;
}

const Material *GeometricObject::material() const
{
    return _material.get();
}

