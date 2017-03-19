# Implemented Features

* orthographic and perspective camera
* rendering of spheres and planes
* diffuse material
* ambient light and point light
* shadows

# To Do

## Featues

* Phong-material
* progressive raytracing for early feedback
* directional light
* area light
* soft shadows
* triangle-intersection and shading (flat, Gouraud, Phong)
* antialiasing
* gamma correction
* fish-eye camera, stereoscopic camera
* import meshes (and materials)

## Technical Stuff

* special versions Scene::trace() and GeometricObject::intersect() for shadow rays which don't
  need the whole Intersection information
* optimize Camera::createRay() implementations with precalculations
* use float instead of double where appropriate
* matrix- and normal-class as needed
* find a more efficient way of single pixel rendering in SDL2 and refresh window after every pixel
* consider rule of 3 (5)
