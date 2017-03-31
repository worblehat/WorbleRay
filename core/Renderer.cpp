#include "Camera.h"
#include "Color.h"
#include "Framebuffer.h"
#include "GeometricObject.h"
#include "Intersection.h"
#include "log.h"
#include "Material.h"
#include "Ray.h"
#include "Renderer.h"
#include "Scene.h"


Renderer::Renderer(const Scene &scene)
    : scene(scene)
    , _abort(false)
{
}


void Renderer::render(Framebuffer &target)
{
    _abort = false;
    render_iterative(target);
}

void Renderer::abort()
{
   _abort = true;
}

void Renderer::render_iterative(Framebuffer &target) const
{
    for(short y = 0; y < target.height && !_abort; ++y)
    {
        Y_POS = y;
        for(short x = 0; x < target.width && !_abort; ++x)
        {
            X_POS = x;
            Color pixel_color = calculate_pixel(x, y);
            target.set_pixel(x, y, pixel_color.r, pixel_color.g, pixel_color.b);
            target.handle_events();
        }
        target.refresh();
    }
}

void Renderer::render_progressive(Framebuffer &target) const
{
    //TODO
}

Color Renderer::calculate_pixel(int x, int y) const
{
    Color pixel_color;
    Ray ray = scene.camera()->create_ray(x, y);
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

    return pixel_color;
}
