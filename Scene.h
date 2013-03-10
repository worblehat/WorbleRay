/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef SCENE_H
#define SCENE_H

//#include "AmbientLight.h"
#include "Camera.h"
#include "Color.h"
#include "GeometricObject.h"
#include "Intersection.h"
#include "Light.h"
#include "Ray.h"

#include <vector>


class GeometricObject; //TODO forward declaration needed here?
class Intersection; //TODO forward declaration needed here?
class Light; //TODO forward declaration needed here?
//class AmbientLight; //TODO forward declaration needed here?

/**
 * \brief Description of a 3D Scene.
 *
 * GeometricObjects, Lights and Cameras can be placed in the scene. In addition the scene has background
 * color and an ambient light intensity.
 * The Scene is able to trace Rays and determine Intersections with GeometricObjects in the Scene.
 */
class Scene
{
    public:
        void add_object(GeometricObject *object);
        void add_light(Light* light);
        const std::vector<Light*> get_lights() const;
        void set_ambient_light(Light* light);   //TODO should be AmbientLight
        Light* get_ambient_light() const;       //TODO should be AmbientLight 
        void set_camera(Camera* camera);
        void set_background(const Color& bg_color);
        const Color& get_background() const;
        Intersection trace(const Ray& ray);
    private:
        std::vector<GeometricObject*> objects;
        std::vector<Light*> lights;
        Light *ambient_light;   //TODO should be AmbientLight
        Camera *camera;
        Color bg_color;
};


inline void Scene::add_object(GeometricObject* object)
{
    objects.push_back(object);
}
        
inline void Scene::add_light(Light* light)
{
    lights.push_back(light);
}
        
inline void Scene::set_ambient_light(Light* light)
{
   ambient_light = light; 
}

inline void Scene::set_camera(Camera* camera)
{
    this->camera = camera;
}
        
inline void Scene::set_background(const Color& bg_color)
{
    this->bg_color = bg_color;
}
        
inline const Color& Scene::get_background() const
{
    return bg_color;
}
        
inline const std::vector<Light*> Scene::get_lights() const
{
    return lights;
}
        
inline Light* Scene::get_ambient_light() const
{
    return ambient_light;
}

#endif // ifndef SCENE_H
