/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Color.h"


/**
 * \brief Abstract base class for lights.
 */
class Light
{
    public:
        virtual ~Light(){};
        virtual Color calc_intensity() const = 0;        
};

#endif //ifndef LIGHT_H
