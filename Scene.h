#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Color.h"
#include "GeometricObject.h"
#include "Light.h"

class Scene
{
    public:
        void add_object(GeometricObject* object);
        void add_light(Light* light);
        void set_camera(Camera* camera);
        void set_background(const Color& bg_color);
        void set_ambient_intensitx(Light* light);
};

#endif // ifndef SCENE_H
