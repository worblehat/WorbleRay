/*
 * Copyright (C) 2013 Tobias Marquardt <tm@tobix.eu>
 *
 * This file is part of WorbleRay, a simple ray tracer which is licensed under 
 * the GNU General Public License v3. You should have received a copy of the 
 * GNU General Public License in the file LICENSE.txt along with this program. 
 * If not, see <http://www.gnu.org/licenses>
 * 
 */

#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include "Framebuffer.h"

#include <SDL/SDL.h>

class SDLWindow : public Framebuffer
{
    public:
        SDLWindow(short width, short height);
        ~SDLWindow();
        virtual void set_pixel(short x, short y, float r, float g, float b);
        virtual void refresh();
    private:
        SDL_Surface *surface_ptr;
};

#endif //ifndef SDL_WINDOW_H
