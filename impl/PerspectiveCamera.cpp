#include "math.h"
#include "log.h"
#include "PerspectiveCamera.h"
#include "PointD3.h"
#include "Ray.h"
#include "VectorD.h"

#include <cmath>


PerspectiveCamera::PerspectiveCamera()
    : Camera()
{
}

void PerspectiveCamera::set_field_of_view(short degree)
{
    fov = math::to_radian(degree % 360);
}

Ray PerspectiveCamera::create_ray(int x, int y) const
{
    Ray ray;
    // side points to the right in camera's perspective
    VectorD side = look_at.cross(up);
    side.normalize();
    // Size of view plane in world space
    float view_w = x_res * pixel_size;
    float view_h = y_res * pixel_size;
    // Vectors spanning the view plane
    VectorD v_down = -up * view_h;
    VectorD v_right = side * view_w;
    // Focal length f (distance between camera position and view plane).
    // f is the adjacent site of a right triangle with angle: fov/2, opposite site: view_w/2
    double f = view_w / (2 * std::tan(fov / 2.0));
    // Vector from camera position to center of view plane
    VectorD v_f = look_at * f;
    // Top-left corner of view plane
    PointD3 v_center = position + v_f;
    PointD3 v_origin = v_center - (v_right / 2.0f) - (v_down / 2.0f);
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
    ray.direction = pixel_pos - position;
    ray.direction.normalize();

    return ray;
}
