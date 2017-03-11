#include "Camera.h"


Camera::Camera()
    : look_at(0.0, 0.0, -1.0)
    , up(0.0, 1.0, 0.0)
    , x_res(100)
    , y_res(100)
    , pixel_size(1.0)
{
}

void Camera::set_position(const PointD &position)
{
  this->position = position;
}

void Camera::set_look_at(const VectorD &look_at)
{
    this->look_at = look_at;
    this->look_at.normalize();
}

void Camera::set_up_vector(const VectorD &up)
{
    this->up = up;
    this->up.normalize();
}

void Camera::set_resolution(int x, int y)
{
  x_res = x;
  y_res = y;
}

void Camera::set_pixel_size(float size)
{
  pixel_size = size;
}

