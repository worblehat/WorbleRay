#include "AmbientLight.h"
#include "Camera.h"
#include "Intersection.h"
#include "GeometricObject.h"
#include "log.h"
#include "Light.h"
#include "Scene.h"

#include <limits>


Scene::Scene()
    : _ambient_light(nullptr)
    , _camera(nullptr)
{
}

Scene::Scene(const Options &options)
    : _ambient_light(nullptr)
    , _camera(nullptr)
    , _options(options)
{
}

void Scene::add_object(std::unique_ptr<GeometricObject> object)
{
    _objects.push_back(std::move(object));
}

void Scene::add_light(std::unique_ptr<Light> light)
{
    _lights.push_back(std::move(light));
}

void Scene::set_ambient_light(std::unique_ptr<AmbientLight> light)
{
    _ambient_light = std::move(light);
}

void Scene::set_camera(std::unique_ptr<Camera> camera)
{
    _camera = std::move(camera);
}

void Scene::set_background(const Color& bg_color)
{
    this->bg_color = bg_color;
}

const Color& Scene::background() const
{
    return bg_color;
}

const std::vector<std::unique_ptr<Light>> &Scene::lights() const
{
    return _lights;
}

AmbientLight *Scene::ambient_light() const
{
    return _ambient_light.get();
}

Camera *Scene::camera() const
{
    return _camera.get();
}

Intersection Scene::trace(const Ray& ray) const
{
    double t_min = std::numeric_limits<double>::max();
    const double e = _options.intersection_epsilon;
    Intersection closest_intersection;
    closest_intersection.exists = false;

    for(auto const &object : _objects)
    {
        Intersection intersection = object->intersect(ray);
        double t = intersection.t;
        if(intersection.exists && t > e && t < t_min)
        {
            closest_intersection = intersection;
            t_min = t;
        }
    }

    return closest_intersection;
}

const Options &Scene::options() const
{
    return _options;
}

