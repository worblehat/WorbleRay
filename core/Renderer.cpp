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

#include <algorithm>
#include <cmath>


Renderer::Renderer(const Scene &scene)
    : scene(scene)
    , _abort(false)
    , inv_gamma(0.0)
{
    double gamma = scene.options().gamma;
    if(gamma != 1.0)
    {
        inv_gamma = 1.0 / gamma;
    }
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

    // Ray tracing
    Ray ray = scene.camera()->create_ray(x, y);
    Intersection intersection = scene.trace(ray);

    // Shading
    if(intersection.exists && intersection.hit_object->material())
    {
        const Material *material = intersection.hit_object->material();
        pixel_color = material->shade(intersection, scene);
    }
    else
    {
        pixel_color = scene.background();
    }

    // Tone mapping
    ToneMapping tm = scene.options().tone_mapping;
    if(ToneMapping::Highlight == tm)
    {
        if(pixel_color.r > 1.0 || pixel_color.g > 1.0 || pixel_color.b > 1.0)
        {
          pixel_color = Color(1.0, 0.75, 0.0);
        }
    }
    else if(ToneMapping::Clamp == tm)
    {
        pixel_color.r = pixel_color.r > 1.0 ? 1.0 : pixel_color.r;
        pixel_color.g = pixel_color.g > 1.0 ? 1.0 : pixel_color.g;
        pixel_color.b = pixel_color.b > 1.0 ? 1.0 : pixel_color.b;
    }
    else if(ToneMapping::Scale == tm)
    {
        double max_value = std::max(pixel_color.r, std::max(pixel_color.g, pixel_color.b));
        if(max_value > 1.0)
        {
            pixel_color /= max_value;
        }
    }

    // Gamma correction
    if(inv_gamma > 0.0)
    {
        pixel_color.r = std::pow(pixel_color.r, inv_gamma);
        pixel_color.g = std::pow(pixel_color.g, inv_gamma);
        pixel_color.b = std::pow(pixel_color.b, inv_gamma);
    }

    return pixel_color;
}
