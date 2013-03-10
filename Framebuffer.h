/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

class Framebuffer
{
    public:
        Framebuffer(short width, short height);
        virtual ~Framebuffer(){};
        virtual void set_pixel(short x, short y, float r, float g, float b) = 0;
        virtual void refresh() = 0;
    protected:
        short width;
        short height;
}; 

inline Framebuffer::Framebuffer(short width, short height)
{
    this->width = width;
    this->height = height;
}

#endif //ifndef FRAMEBUFFER_H
