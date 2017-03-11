# Implemented Features

* orthographic camera
* sphere intersection
* lambert material

# To Do

## Featues

* perspective camera
* Phong-material
* plane-intersection
* progressive raytracing for early feedback
* directional light
* area light
* triangle-intersection and shading (flat, Gouraud, Phong)
* import meshes (and materials)
* antialiasing
* shadows (epsilon in intersections? See [Suffer:2014] sec. 3.4.1)

## Technical Stuff

* use float instead of double where appropriate
* matrix- and normal-class as needed
* Find a more efficient way of single pixel rendering in SDL2 and refresh window after every pixel
* consider rule of 3 (5)
