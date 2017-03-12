#include "GeometricObject.h"


GeometricObject::GeometricObject()
    : _material(nullptr)
{
}

void GeometricObject::set_material(std::shared_ptr<Material> material)
{
    _material = material;
}

const Material *GeometricObject::material() const
{
    return _material.get();
}

