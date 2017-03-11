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

    virtual Ray createRay(int x, int y) const override;
};

#endif //ifndef ORTHOGRAPHICCAMERA_H
