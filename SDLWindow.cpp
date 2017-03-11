#include "SDLWindow.h"

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>


SDLWindow::SDLWindow(short width, short height)
    : Framebuffer(width, height)
{
}

bool SDLWindow::show()
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        std::cout << "ERROR: Can't initialize SDL. " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("WorbleRay", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, 0);
    if(!window)
    {
        std::cout << "ERROR: Cannot initialize SDL-window. " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        std::cout << "ERROR: Cannot initialize SDL-renderer. " << SDL_GetError() << std::endl;
        return false;
    }

    int bpp;
    Uint32 Rmask, Gmask, Bmask, Amask;
    if(!SDL_PixelFormatEnumToMasks(SDL_PIXELFORMAT_RGB888, &bpp, &Rmask, &Gmask, &Bmask, &Amask))
    {
        std::cout << "ERROR: Cannot create SDL-pixelformat. " << SDL_GetError() << std::endl;
        return false;
    }

    surface = SDL_CreateRGBSurface(0, width, height, bpp, Rmask, Gmask, Bmask, Amask);
    if(!surface)
    {
        std::cout << "ERROR: Cannot initialize SDL-surface. " << SDL_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture)
    {
        std::cout << "ERROR: Cannot initialize SDL-texture. " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

SDLWindow::~SDLWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLWindow::set_pixel(short x, short y, float r, float g, float b)
{
    Uint32 color = SDL_MapRGB(surface->format, (Uint8) 255*r, (Uint8) 255*g, (Uint8) 255*b);
    Uint32 *pixel_ptr = (Uint32*)surface->pixels + y * width + x;
    *pixel_ptr = color;
}

void SDLWindow::refresh()
{
    SDL_UpdateTexture(texture, nullptr, surface->pixels, surface->pitch);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void SDLWindow::handle_events()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(SDL_QUIT == event.type)
        {
            on_quit_callback();
        }
    }
}

void SDLWindow::on_quit(std::function<void()> callback)
{
    on_quit_callback = callback;
}
