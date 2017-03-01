
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
