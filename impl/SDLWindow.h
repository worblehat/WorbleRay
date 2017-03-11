#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include "Framebuffer.h"

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>


class SDLWindow : public Framebuffer
{
public:
    SDLWindow(short width, short height);
    ~SDLWindow();
    virtual bool show() override;
    virtual void set_pixel(short x, short y, float r, float g, float b) override;
    virtual void refresh() override;
    virtual void handle_events() override;
    virtual void on_quit(std::function<void()> callback) override;
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    std::function<void()> on_quit_callback;
};

#endif //ifndef SDL_WINDOW_H
