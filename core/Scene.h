#ifndef SCENE_H
#define SCENE_H

#include "Color.h"

#include <memory>
#include <vector>

class AmbientLight;
class Camera;
class Color;
class GeometricObject;
class Intersection;
class Light;
class Ray;


/**
 * \brief Description of a 3D Scene.
 *
 * GeometricObjects, Lights and Cameras can be placed in the scene. In addition the scene has background
 * color and an ambient light intensity.
 * The Scene is able to trace Rays and determine Intersections with GeometricObjects in the Scene.
 * A right-handed coordinate system is used.
 */
class Scene
{
public:
    void add_object(std::unique_ptr<GeometricObject> object);
    void add_light(std::unique_ptr<Light> light);
    const std::vector<std::unique_ptr<Light>> &lights() const;
    void set_ambient_light(std::unique_ptr<AmbientLight> light);
    AmbientLight* ambient_light() const;
    void set_camera(std::unique_ptr<Camera> camera);
    void set_background(const Color& bg_color);
    const Color& background() const;
    Intersection trace(const Ray& ray);
private:
    std::vector<std::unique_ptr<GeometricObject>> _objects;
    std::vector<std::unique_ptr<Light>> _lights;
    std::unique_ptr<AmbientLight> _ambient_light;
    std::unique_ptr<Camera> _camera;
    Color bg_color;
};

#endif // ifndef SCENE_H
