#include "OrthographicCamera.h"
#include "PointD3.h"
#include "Ray.h"
#include "VectorD.h"


OrthographicCamera::OrthographicCamera()
{
}

Ray OrthographicCamera::create_ray(int x, int y) const
{
    Ray ray;
    ray.direction = look_at;
    // side points to the right in camera's perspective
    VectorD side = look_at.cross(up);
    side.normalize();
    // Size of view plane in world space
    float view_w = x_res * pixel_size;
    float view_h = y_res * pixel_size;
    // Vectors spanning the view plane
    VectorD v_down = -up * view_h;
    VectorD v_right = side * view_w;
    PointD3 v_origin = position - (v_right / 2.0f) - (v_down / 2.0f);
    // Normalized pixel positions [0,1]
    float n_x = (float)x / x_res;
    float n_y = (float)y / y_res;
    // Pixel position in world space
    PointD3 pixel_pos = v_origin + (v_right * n_x) + (v_down * n_y);
    // Adjust to center of pixel
    v_right.normalize();
    v_down.normalize();
    pixel_pos += v_right * (pixel_size / 2.0f) + v_down * (pixel_size / 2.0f);
    ray.origin = pixel_pos;

    return ray;
}
