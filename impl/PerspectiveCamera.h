#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "Camera.h"


class PerspectiveCamera : public Camera
{
public:
    PerspectiveCamera();

    void set_field_of_view(short degree);
    virtual Ray create_ray(int x, int y) const override;

private:
    //! Field of view in radian
    double fov;
};

#endif // PERSPECTIVECAMERA_H
