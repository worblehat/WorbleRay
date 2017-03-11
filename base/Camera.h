#ifndef CAMERA_H
#define CAMERA_H

#include "PointD.h"
#include "VectorD.h"

class Ray;


/**
 * TODO doc camera and view, origin top-left corner, x/y zero-based,
 *          up-vector and look-at must be perpendicular
 */
class Camera
{
public:
    Camera();
    virtual ~Camera() = default;

    virtual Ray createRay(int x, int y) const = 0;
    void set_position(const PointD &position);
    void set_look_at(const VectorD &look_at);
    void set_up_vector(const VectorD &up);
    void set_resolution(int x, int y);
    void set_pixel_size(float size);

protected:
    // Camera attributes
    PointD position;
    VectorD look_at;
    VectorD up;
    // View plane attributes
    int x_res;
    int y_res;
    float pixel_size;
};

#endif //ifndef CAMERA_H
