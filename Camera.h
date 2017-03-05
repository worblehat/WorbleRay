
#ifndef CAMERA_H
#define CAMERA_H

#include "mathutil.h"
#include "Ray.h"

/**
 * TODO doc camera and view, origin top-left corner, x/y zero-based,
 *          up-vector and look-at must be perpendicular
 */
class Camera
{
    public:
        Camera();
        virtual ~Camera();

        virtual Ray createRay(int x, int y) const = 0;
        void set_position(const Vector4f &position);
        void set_look_at(const Vector4f &look_at);
        void set_up_vector(const Vector4f &up);
        void set_resolution(int x, int y);
        void set_pixel_size(float size);

    protected:
        // Camera attributes
        Vector4f position;
        Vector4f look_at;
        Vector4f up;
        // View plane attributes
        int x_res;
        int y_res;
        float pixel_size;
};

#endif //ifndef CAMERA_H
