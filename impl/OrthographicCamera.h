#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#include "Camera.h"


/**
 * @brief TODO doc: camera position at center of view-plane
 */
class OrthographicCamera : public Camera
{
public:
    OrthographicCamera();

    virtual Ray create_ray(int x, int y) const override;
    virtual Ray create_ray(int x, int y, const PointD2 &sample_point) const override;
};

#endif //ifndef ORTHOGRAPHICCAMERA_H
