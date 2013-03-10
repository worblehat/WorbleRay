/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#include "AmbientLight.h"
#include "Intersection.h"
#include "LambertMaterial.h"
#include "mathutil.h"
#include "Plane.h"
#include "PointLight.h"
#include "Ray.h"
#include "SDLWindow.h"
#include "Scene.h"
#include "Sphere.h"

#include <cstdlib>
#include <iostream>


int main(int argc, char *argv[])
{
    // Process command line arguments
    int width, height;
    if(argc == 3)
    {
        width = atoi(argv[1]); 
        height = atoi(argv[2]);
    }
    else
    {
        std::cout << "ERROR: wrong number of command line arguments" << std::endl;
        exit(1);
    }
    
    // Define objects
    Plane *plane = new Plane(Vector4d(0.0, 0.0, 0.0, 1.0), Vector4d(0.0, 0.0, 1.0, 0.0));
    Sphere *sphere = new Sphere(Vector4d(0.0, 0.0, 0.0, 1.0), 25.0);

    // Specify materials
    LambertMaterial *flat_lambert = new LambertMaterial(Color(0.6f, 0.0f, 0.0f), Color(0.5f, 0.0f, 0.0f));
    plane->set_material(flat_lambert);
    sphere->set_material(flat_lambert);

    // Add objects to scene
    Scene scene;
//    scene.add_object(plane);
    scene.add_object(sphere);

    // Set light sources
    AmbientLight *ambient_light = new AmbientLight(Color(0.2f, 0.2f, 0.2f), 1.0f);
    PointLight *point_light = new PointLight(Vector4d(50.0f, 100.0f, 100.0f, 1.0f), Color(0.6f, 0.6f, 0.6f));
    scene.set_ambient_light(ambient_light);
    scene.set_ambient_light(point_light);

    // Define render window
    Framebuffer *window = new SDLWindow(width, height);
    
    Ray ray;
    Color pixel_color;
    // For each pixel
    for(short y = 0; y < height; ++y)
    {
        for(short x = 0; x < width; ++x)
        {
            // Create ray through pixel 
            // TODO maybe member function of Camera?
            // TODO Remove and rewrite this later:
            float pixel_size = 1.0f;
            float r_x = pixel_size * (x - width / 2.0 + 0.5f);
            float r_y = pixel_size * (y - height / 2.0 + 0.5f);
            float view_z = 100.0f;
            // Orthographic view:
            ray.set_origin(Vector4d(r_x, r_y, view_z, 1.0));
            ray.set_direction(Vector4d(0.0, 0.0, -1.0, 0.0));
            
            // Trace ray 
            Intersection intersection = scene.trace(ray);

            // Shade intersction point
            if(intersection.get_exists())
            {
               pixel_color = intersection.get_hit_object()->get_material()->shade(intersection, scene);
            }    
            else
            {
               pixel_color = scene.get_background(); 
            }
            
            // Set pixel color
            window->set_pixel(x, y, pixel_color.get_r(), pixel_color.get_g(), pixel_color.get_b());
        }

        // Redraw
        window->refresh();
    }

    char i;
    std::cin >> i;

    delete window;

    return 0;
}
