
#include "OrthographicCamera.h"


OrthographicCamera::OrthographicCamera()
{
}

Ray OrthographicCamera::createRay(int x, int y) const
{
  Ray ray;
  ray.set_direction(look_at);
  Vector3f look_at_3d(look_at);
  Vector3f up_3d(up);
  // side points to the right in camera's perspective
  Vector4f side(glm::cross(look_at_3d, up_3d), 0.0);
  side = glm::normalize(side);
  // Size of view plane in world space
  float view_w = x_res * pixel_size;
  float view_h = y_res * pixel_size;
  // Vectors spanning the view plane
  Vector4f v_down = -up * view_h;
  Vector4f v_right = side * view_w;
  Vector4f v_origin = position - (v_right / 2.0f) - (v_down / 2.0f);
  // Normalized pixel positions [0,1]
  float n_x = (float)x / x_res;
  float n_y = (float)y / y_res;
  // Pixel position in world space
  Vector4f pixel_pos = v_origin + (v_right * n_x) + (v_down * n_y);
  // Adjust to center of pixel
  v_right = glm::normalize(v_right);
  v_down = glm::normalize(v_down);
  pixel_pos += v_right * (pixel_size / 2.0f) + v_down * (pixel_size / 2.0f);
  ray.set_origin(pixel_pos);

  return ray;
}
