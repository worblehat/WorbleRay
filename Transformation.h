/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "mathutil.h"

/**
 * \brief Affine transformation wrapping a 4x4 hogoneneous transformation matrix.
 *
 * Provides some convinience methods to construct standard transformations like translation,
 * rotation and scaling.
 * \TODO implement these members...
 */
class Transformation
{
    public:
        Transformation();
    private:
        Matrix4d transform_matrix;
        Matrix4d inv_transform_matrix;
};

inline Transformation::Transformation()
 : transform_matrix(1.0)
 , inv_transform_matrix(1.0)
{
} 

#endif //ifndef TRANSFORMATION_H

