#include "SDLWindow.h"

#include <iostream>


SDLWindow::SDLWindow(short width, short height)
 : Framebuffer(width, height)
{
    this->width = width;
    this->height = height;
    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        std::cout << "ERROR: Can't initialize SDL" << std::endl;
        exit(1);
    }
    // Init display
    if((surface_ptr = SDL_SetVideoMode(width, height, 32, SDL_ANYFORMAT)) == NULL)
    {
        std::cout << "ERROR :Can't set up video mode" << std::endl;
        exit(1);
    }  
}

SDLWindow::~SDLWindow()
{
    SDL_Quit();
}

void SDLWindow::set_pixel(short x, short y, float r, float g, float b)
{
    Uint32 color = SDL_MapRGB(surface_ptr->format, (Uint8) 255*r, (Uint8) 255*g, (Uint8) 255*b);
    Uint32 *pixel_ptr = (Uint32*)surface_ptr->pixels + y * width + x;
    *pixel_ptr = color;
}

void SDLWindow::refresh()
{
    if(SDL_Flip(surface_ptr) == -1)
    {
        std::cout << "ERROR: Can't update dispaly" << std::endl;
        exit(1);
    }
}
