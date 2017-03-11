#include "AmbientLight.h"
#include "Intersection.h"
#include "LambertMaterial.h"
#include "log.h"
#include "OrthographicCamera.h"
#include "PerspectiveCamera.h"
#include "Plane.h"
#include "PointLight.h"
#include "Ray.h"
#include "SDLWindow.h"
#include "Scene.h"
#include "Sphere.h"

#include <cstdlib>
#include <memory>


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
        ERROR("Wrong number of command line arguments.")
        exit(1);
    }

    Scene scene;

    // Define objects
    auto plane = std::unique_ptr<Plane>(new Plane(PointD(0.0, 0.0, -150.0), VectorD(0.0, 0.0, 1.0)));
    auto sphere_1 = std::unique_ptr<Sphere>(new Sphere(PointD(0.0, 0.0, -150.0), 100.0));
    auto sphere_2 = std::unique_ptr<Sphere>(new Sphere(PointD(80.0, 0.0, -400.0), 100.0));

    // Specify materials
    auto red_lambert = std::make_shared<LambertMaterial>(Color(0.6f, 0.0f, 0.0f), Color(0.5f, 0.0f, 0.0f));
    auto blue_lambert = std::make_shared<LambertMaterial>(Color(0.0f, 0.0f, 0.6f), Color(0.0f, 0.0f, 0.5f));
    plane->set_material(red_lambert);
    sphere_1->set_material(red_lambert);
    sphere_2->set_material(blue_lambert);

    //scene.add_object(std::move(plane));
    scene.add_object(std::move(sphere_1));
    scene.add_object(std::move(sphere_2));

    // Set light sources
    auto ambient_light = std::unique_ptr<AmbientLight>(
                new AmbientLight(Color(0.3f, 0.3f, 0.3f), 1.0f));
    auto point_light = std::unique_ptr<PointLight>(
            new PointLight(PointD(100.0f, 100.0f, 100.0f), Color(0.7f, 0.7f, 0.7f)));
    scene.set_ambient_light(std::move(ambient_light));
    scene.add_light(std::move(point_light));

    // Define render window
    SDLWindow window(width, height);
    bool quit = false;
    window.on_quit([&quit]()
        {
            quit = true;
        }
    );
    quit = !window.show();

    Ray ray;
    Color pixel_color;
    PerspectiveCamera camera;
    camera.set_field_of_view(90);
    camera.set_position(PointD(0.0f, 0.0f, 400.0f));
    camera.set_look_at(VectorD(0.0f, 0.0f, -1.0f));
    camera.set_up_vector(VectorD(0.0f, 1.0f, 0.0f));
    camera.set_resolution(width, height);
    camera.set_pixel_size(1.0f);
    // For each pixel
    for(short y = 0; y < height && !quit; ++y)
    {
        for(short x = 0; x < width && !quit; ++x)
        {
            ray = camera.create_ray(x, y);
            Intersection intersection = scene.trace(ray);

            if(intersection.exists)
            {
                const Material *material = intersection.hit_object->material();
                pixel_color = material->shade(intersection, scene);
            }
            else
            {
                pixel_color = scene.background();
            }

            window.set_pixel(x, y, pixel_color.r, pixel_color.g, pixel_color.b);
            window.handle_events();
        }
        window.refresh();
    }

    while(!quit)
    {
        window.handle_events();
    }

    return 0;
}
