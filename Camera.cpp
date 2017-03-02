
#include "Camera.h"

Camera::Camera()
    : look_at(0.0, 0.0, -1.0, 0.0)
    , up(0.0, 1.0, 0.0, 0.0)
    , x_res(100)
    , y_res(100)
    , pixel_size(1.0)
{
}

Camera::~Camera()
{
}

void Camera::set_position(const Vector4f &position)
{
  this->position = position;
}

void Camera::set_look_at(const Vector4f &look_at)
{
  this->look_at = glm::normalize(look_at);
}

void Camera::set_up_vector(const Vector4f &up)
{
  this->up = glm::normalize(up);
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

