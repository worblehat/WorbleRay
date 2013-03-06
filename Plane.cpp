/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#include "Plane.h"


const Intersection Plane::intersect(const Ray& ray)
{
    Intersection intersection;
    //TODO NEXT
    intersection.set_hit_object(this);
    intersection.set_exists(true);
    return intersection;
}

