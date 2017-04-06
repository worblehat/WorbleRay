#include "Camera.h"
#include "Color.h"
#include "Framebuffer.h"
#include "GeometricObject.h"
#include "Intersection.h"
#include "log.h"
#include "Material.h"
#include "math.h"
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
    const RenderProgression progression = scene.options().progression;
    if(RenderProgression::ITERATIVE == progression)
    {
        render_iterative(target);
    }
    else if(RenderProgression::UNIFORM_PROGRESSIVE == progression)
    {
       render_progressive(target);
    }
    else if(RenderProgression::UNIFORM_PROGRESSIVE_2 == progression)
    {
       render_progressive_with_lookup(target);
    }
}

void Renderer::abort()
{
   _abort = true;
}

/**
 * @brief TODO doc
 */
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

/**
 * @brief TODO doc
 */
void Renderer::render_progressive(Framebuffer &target) const
{
    short initial_step = math::next_power_of_two(std::max(target.width, target.height));

    for(short step = initial_step; step > 0; step = step / 2)
    {
        for(short y = 0; y < target.height && !_abort; y += step)
        {
            Y_POS = y;
            if(step == initial_step || (y / step) % 2 == 1)
            {
                for(short x = 0; x < target.width && !_abort; x += step)
                {
                    X_POS = x;
                    render_rect(x, y, step, target);
                }
            }
            else
            {
                for(short x = step; x < target.width && !_abort; x += step * 2)
                {
                    X_POS = x;
                    render_rect(x, y, step, target);
                }
            }
            target.handle_events();
            target.refresh();
        }
    }
}

/**
 * @brief TODO doc
 */
void Renderer::render_progressive_with_lookup(Framebuffer &target) const
{
    bool finished[target.height][target.width];
    //TODO init
    //TODO NEXT
}

void Renderer::render_rect(short x, short y, short step, Framebuffer &target) const
{
    Color pixel_color = calculate_pixel(x, y);
    for(short j = y; j < y + step && j < target.height; ++j)
    {
       for(short i = x; i < x + step && i < target.width; ++i)
       {
          target.set_pixel(i, j, pixel_color.r, pixel_color.g, pixel_color.b);
       }
    }
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
    if(ToneMapping::HIGHLIGHT == tm)
    {
        if(pixel_color.r > 1.0 || pixel_color.g > 1.0 || pixel_color.b > 1.0)
        {
          pixel_color = Color(1.0, 0.75, 0.0);
        }
    }
    else if(ToneMapping::CLAMP == tm)
    {
        pixel_color.r = pixel_color.r > 1.0 ? 1.0 : pixel_color.r;
        pixel_color.g = pixel_color.g > 1.0 ? 1.0 : pixel_color.g;
        pixel_color.b = pixel_color.b > 1.0 ? 1.0 : pixel_color.b;
    }
    else if(ToneMapping::SCALE == tm)
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
