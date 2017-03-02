#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#include "Camera.h"

class OrthographicCamera : public Camera
{
    public:
        OrthographicCamera();

        virtual Ray createRay(int x, int y) const override;
};

#endif //ifndef ORTHOGRAPHICCAMERA_H
