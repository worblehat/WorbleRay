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
