#ifndef CAMERA_H
#define CAMERA_H

#include "PointD2.h"
#include "PointD3.h"
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

    /*!
     * \brief Create a ray through a pixel.
     *
     * The ray will pass through the center of the pixel.
     * \param x X-index of the pixel.
     * \param y y-index of the pixel.
     */
    virtual Ray create_ray(int x, int y) const = 0;
    /*!
     * \brief Create a ray through a pixel.
     * \param x X-index of the pixel.
     * \param y y-index of the pixel.
     * \param sample_point Offset inside the pixel [0,1]²
     */
    virtual Ray create_ray(int x, int y, const PointD2 &sample_point) const = 0;

    void set_position(const PointD3 &position);
    void set_look_at(const VectorD &look_at);
    void set_up_vector(const VectorD &up);
    void set_resolution(int x, int y);
    void set_pixel_size(float size);

protected:
    // Camera attributes
    PointD3 position;
    VectorD look_at;
    VectorD up;
    // View plane attributes
    int x_res;
    int y_res;
    float pixel_size;
};

#endif //ifndef CAMERA_H
