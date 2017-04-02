#include "AmbientLight.h"
#include "Intersection.h"
#include "LambertMaterial.h"
#include "log.h"
#include "OrthographicCamera.h"
#include "PerspectiveCamera.h"
#include "PhongMaterial.h"
#include "Plane.h"
#include "PointLight.h"
#include "Ray.h"
#include "Renderer.h"
#include "SDLWindow.h"
#include "Scene.h"
#include "Sphere.h"

#include <chrono>
#include <cstdlib>
#include <memory>
#include <thread>


// Declared in log.h, defined here
short X_POS;
short Y_POS;

int main()
{
    // Optionen
    Options options;
    options.width = 960;
    options.height = 600;
    options.ambient_illumination = true;
    options.diffuse_illumination = true;
    options.specular_illumination = true;
    options.shadows = true;
    options.intersection_epsilon = 0.0000000001;
    options.gamma = 1.4;
    options.tone_mapping = ToneMapping::Scale;
    options.max_recursion = 4;

    // Build scene
    Scene scene(options);

    auto floor = std::unique_ptr<Plane>(new Plane(PointD(0.0, 0.0, 0.0), VectorD(0.0, 1.0, 0.0)));
    auto wall_left = std::unique_ptr<Plane>(new Plane(PointD(-800.0, 0.0, 0.0), VectorD(1.0, 0.0, 0.0)));
    auto wall_right = std::unique_ptr<Plane>(new Plane(PointD(800.0, 0.0, 0.0), VectorD(-1.0, 0.0, 0.0)));
    auto wall_back = std::unique_ptr<Plane>(new Plane(PointD(0.0, 0.0, -1000.0), VectorD(0.0, 0.0, 1.0)));
    auto wall_front = std::unique_ptr<Plane>(new Plane(PointD(0.0, 0.0, 2500.0), VectorD(0.0, 0.0, -1.0)));
    auto ceiling = std::unique_ptr<Plane>(new Plane(PointD(0.0, 1100.0, 0.0), VectorD(0.0, -1.0, 0.0)));
    auto sphere_1 = std::unique_ptr<Sphere>(new Sphere(PointD(0.0, 200.0, -450.0), 200.0));
    auto sphere_2 = std::unique_ptr<Sphere>(new Sphere(PointD(300.0, 150.0, -200.0), 150.0));

    auto perspective_cam = std::unique_ptr<PerspectiveCamera>(new PerspectiveCamera());
    perspective_cam->set_field_of_view(50);
    perspective_cam->set_position(PointD(0.0f, 800.0f, 2200.0f));
    perspective_cam->set_look_at(VectorD(0.0f, -0.15f, -1.0f));
    perspective_cam->set_up_vector(VectorD(0.0f, 1.0f, 0.0f));
    perspective_cam->set_resolution(options.width, options.height);
    perspective_cam->set_pixel_size(1.0f);
    scene.set_camera(std::move(perspective_cam));

    auto ambient_light = std::unique_ptr<AmbientLight>(
                new AmbientLight(Color(0.3f, 0.3f, 0.3f), 1.0f));
    auto point_light = std::unique_ptr<PointLight>(
            new PointLight(PointD(500.0f, 1000.0f, 0.0f), Color(0.7f, 0.7f, 0.7f)));
    scene.set_ambient_light(std::move(ambient_light));
    scene.add_light(std::move(point_light));

    auto red_phong = std::make_shared<PhongMaterial>(
                Color(0.6f, 0.0f, 0.0f), Color(0.5f, 0.0f, 0.0f), Color(0.6f, 0.6f, 0.6f), 20.0);
    auto blue_phong = std::make_shared<PhongMaterial>(
                Color(0.0f, 0.0f, 0.6f), Color(0.0f, 0.0f, 0.5f), Color(0.0f, 0.0f, 0.6f), 5.0);
    auto green_lambert = std::make_shared<LambertMaterial>(Color(0.0f, 0.6f, 0.0f), Color(0.0f, 0.5f, 0.0f));
    auto light_gray_lambert = std::make_shared<LambertMaterial>(Color(0.8f, 0.8f, 0.8f), Color(0.5f, 0.5f, 0.5f));
    auto dark_gray_lambert = std::make_shared<LambertMaterial>(Color(0.5f, 0.5f, 0.5f), Color(0.2f, 0.2f, 0.2f));
    floor->set_material(green_lambert);
    wall_left->set_material(light_gray_lambert);
    wall_right->set_material(light_gray_lambert);
    wall_back->set_material(light_gray_lambert);
    wall_front->set_material(light_gray_lambert);
    ceiling->set_material(dark_gray_lambert);
    sphere_1->set_material(red_phong);
    sphere_2->set_material(blue_phong);

    scene.add_object(std::move(floor));
    scene.add_object(std::move(ceiling));
    scene.add_object(std::move(wall_left));
    scene.add_object(std::move(wall_right));
    scene.add_object(std::move(wall_back));
    scene.add_object(std::move(wall_front));
    scene.add_object(std::move(sphere_1));
    scene.add_object(std::move(sphere_2));

    // Render
    SDLWindow window(options.width, options.height);
    Renderer renderer(scene);

    bool quit = false;
    window.on_quit([&renderer, &quit]()
        {
            renderer.abort();
            quit = true;
        }
    );

    quit = !window.show();
    if(!quit)
    {
      renderer.render(window);
    }

    // Idle
    while(!quit)
    {
        std::chrono::milliseconds t(30);
        std::this_thread::sleep_for(t);
        window.handle_events();
    }

    return 0;
}
