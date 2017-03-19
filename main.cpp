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

// Declared in log.h, defined here
short X_POS;
short Y_POS;

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

    Options options;
    options.ambient_illumination = true;
    options.diffuse_illumination = true;

    Scene scene(options);

    // Define objects
    auto floor = std::unique_ptr<Plane>(new Plane(PointD(0.0, -400.0, 0.0), VectorD(0.0, 1.0, 0.0)));
    auto wall_left = std::unique_ptr<Plane>(new Plane(PointD(-400.0, 0.0, 0.0), VectorD(1.0, 0.0, 0.0)));
    auto wall_right = std::unique_ptr<Plane>(new Plane(PointD(400.0, 0.0, 0.0), VectorD(-1.0, 0.0, 0.0)));
    auto wall_back = std::unique_ptr<Plane>(new Plane(PointD(0.0, 0.0, -800.0), VectorD(0.0, 0.0, 1.0)));
    auto ceiling = std::unique_ptr<Plane>(new Plane(PointD(0.0, 400.0, 0.0), VectorD(0.0, -1.0, 0.0)));
    auto sphere_1 = std::unique_ptr<Sphere>(new Sphere(PointD(0.0, -250.0, -450.0), 150.0));
    auto sphere_2 = std::unique_ptr<Sphere>(new Sphere(PointD(180.0, -300.0, -300.0), 100.0));

    // Specify materials
    auto red_lambert = std::make_shared<LambertMaterial>(Color(0.6f, 0.0f, 0.0f), Color(0.5f, 0.0f, 0.0f));
    auto green_lambert = std::make_shared<LambertMaterial>(Color(0.0f, 0.6f, 0.0f), Color(0.0f, 0.5f, 0.0f));
    auto blue_lambert = std::make_shared<LambertMaterial>(Color(0.0f, 0.0f, 0.6f), Color(0.0f, 0.0f, 0.5f));
    auto light_gray_lambert = std::make_shared<LambertMaterial>(Color(0.8f, 0.8f, 0.8f), Color(0.5f, 0.5f, 0.5f));
    auto dark_gray_lambert = std::make_shared<LambertMaterial>(Color(0.5f, 0.5f, 0.5f), Color(0.2f, 0.2f, 0.2f));
    floor->set_material(green_lambert);
    wall_left->set_material(light_gray_lambert);
    wall_right->set_material(light_gray_lambert);
    wall_back->set_material(light_gray_lambert);
    ceiling->set_material(dark_gray_lambert);
    sphere_1->set_material(red_lambert);
    sphere_2->set_material(blue_lambert);

    scene.add_object(std::move(floor));
    scene.add_object(std::move(ceiling));
    scene.add_object(std::move(wall_left));
    scene.add_object(std::move(wall_right));
    scene.add_object(std::move(wall_back));
    scene.add_object(std::move(sphere_1));
    scene.add_object(std::move(sphere_2));

    // Set light sources
    auto ambient_light = std::unique_ptr<AmbientLight>(
                new AmbientLight(Color(0.3f, 0.3f, 0.3f), 1.0f));
    auto point_light = std::unique_ptr<PointLight>(
            new PointLight(PointD(200.0f, 300.0f, 0.0f), Color(0.7f, 0.7f, 0.7f)));
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
    auto perspective_cam = std::unique_ptr<PerspectiveCamera>(new PerspectiveCamera());
    perspective_cam->set_field_of_view(60);
    perspective_cam->set_position(PointD(0.0f, 0.0f, 500.0f));
    perspective_cam->set_look_at(VectorD(0.0f, 0.0f, -1.0f));
    perspective_cam->set_up_vector(VectorD(0.0f, 1.0f, 0.0f));
    perspective_cam->set_resolution(width, height);
    perspective_cam->set_pixel_size(1.0f);
    scene.set_camera(std::move(perspective_cam));

    // For each pixel
    Camera *camera = scene.camera();
    if(!camera)
    {
        //TODO
    }
    for(short y = 0; y < height && !quit; ++y)
    {
        Y_POS = y;
        for(short x = 0; x < width && !quit; ++x)
        {
            X_POS = x;
            ray = camera->create_ray(x, y);
            Intersection intersection = scene.trace(ray);

            if(intersection.exists && intersection.hit_object->material())
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
