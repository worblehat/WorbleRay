
#include "AmbientLight.h"
#include "Intersection.h"
#include "LambertMaterial.h"
#include "OrthographicCamera.h"
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
    Sphere *sphere = new Sphere(Vector4d(0.0, 0.0, -150.0, 1.0), 100.0);

    // Specify materials
    LambertMaterial *flat_lambert =
      new LambertMaterial(Color(0.6f, 0.0f, 0.0f), Color(0.5f, 0.0f, 0.0f));
    plane->set_material(flat_lambert);
    sphere->set_material(flat_lambert);

    // Add objects to scene
    Scene scene;
//    scene.add_object(plane);
    scene.add_object(sphere);

    // Set light sources
    AmbientLight *ambient_light = new AmbientLight(Color(0.3f, 0.3f, 0.3f), 1.0f);
    PointLight *point_light =
      new PointLight(Vector4d(100.0f, 100.0f, 100.0f, 1.0f), Color(0.7f, 0.7f, 0.7f));
    scene.set_ambient_light(ambient_light);
    scene.add_light(point_light);

    // Define render window
    Framebuffer *window = new SDLWindow(width, height);

    Ray ray;
    Color pixel_color;
    OrthographicCamera camera;
    camera.set_position(Vector4f(0.0f, 0.0f, 0.0f, 1.0f));
    camera.set_look_at(Vector4f(0.0f, 0.0f, -1.0f, 0.0f));
    camera.set_up_vector(Vector4f(0.0f, 1.0f, 0.0f, 0.0f));
    camera.set_resolution(width, height);
    camera.set_pixel_size(1.0f);
    // For each pixel
    for(short y = 0; y < height; ++y)
    {
        for(short x = 0; x < width; ++x)
        {
            ray = camera.createRay(x, y);
            Intersection intersection = scene.trace(ray);

            // Shade intersction point
            if(intersection.get_exists())
            {
               const Material *material = intersection.get_hit_object()->get_material();
               pixel_color = material->shade(intersection, scene);
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
