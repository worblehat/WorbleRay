# Implemented Features

* orthographic and perspective camera
* rendering of spheres, planes and disks
* matte, glossy and mirror materials
* ambient and point light
* shadows
* tone mapping and gamma correction

# To Do

## Featues

* progressive raytracing for early feedback
* directional light
* area light
* implicit torus-object
* refraction
* distributed ray tracing:
  * antialiasing
  * soft shadows
* ambient occlusion
* triangle-intersection and shading (flat, Gouraud, Phong)
* fish-eye camera, stereoscopic camera
* import meshes (and materials)
* advanced tone mapping
* save image to file (SDLImageFile, SDL_SaveBMP)
* acceleration with bounding volumes
* global diffuse illumination (Photon Mapping, Path Tracing...)

## Technical Stuff

* special versions Scene::trace() and GeometricObject::intersect() for shadow rays which don't
  need the whole Intersection information
* intensity clipping vs intensity scaling (see http://bit.ly/2nSqbJl)
* optimize Camera::createRay() implementations with precalculations
* use float instead of double where appropriate
* matrix- and normal-class as needed
* find a more efficient way of single pixel rendering in SDL2 and refresh window after every pixel
* consider rule of 3 (5)
