# Implemented Features

* orthographic and perspective camera
* rendering of spheres, planes and disks
* matte, glossy and mirror materials
* ambient and point light
* shadows
* tone mapping and gamma correction
* progressive raytracing for early feedback
* anti-aliasing via super sampling

# To Do

## Featues

* directional light
* soft shadows
* area light
* transformable objects and transformations
* refraction
* ambient occlusion
* triangle-intersection and shading (flat, Gouraud, Phong)
* fish-eye camera, stereoscopic camera
* import meshes (and materials)
* advanced tone mapping
* save image to file (SDLImageFile, SDL_SaveBMP)
* acceleration with bounding volumes
* global diffuse illumination (Photon Mapping, Path Tracing...)

## Technical Stuff

* precalculate samples and reuse them; avoid creating new sampler for every pixel
* tone mapping and gamma correction before or after averaging AA-samples?
* special versions Scene::trace() and GeometricObject::intersect() for shadow rays which don't
  need the whole Intersection information
* optimize Camera::createRay() implementations with precalculations
* use float instead of double where appropriate
* find a more efficient way of single pixel rendering in SDL2 and refresh window after every pixel
* consider rule of 3 (5)
* avoid the repeated if-else-checks ins Renderer::calculate_pixel()
